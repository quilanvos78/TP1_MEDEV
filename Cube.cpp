#include "Cube.h"

/* Affichage du monde */

Cube::Cube(int _n) {
	root = new osg::Group;
	n = _n;
}

int Cube::init()
{
/* OBJECTS CREATION */

	//Creating the viewer	
	osgViewer::Viewer viewer;
	/*viewer.realize();
	viewer.getCamera()->setProjectionMatrixAsPerspective(60.0,16.0/9.0,0.1,10.0);
	viewer.getCamera()->setViewMatrix(osg::Matrix::lookAt(osg::Vec3f(0, -1, 2),osg::Vec3f(0, 0, 0),osg::Vec3f(0, 0, 1)));
	*/
	// StateSet de root
	osg::ref_ptr<osg::StateSet> rootStateSet (root->getOrCreateStateSet());

/* TERRAIN */
	
	osg::ref_ptr<osg::PositionAttitudeTransform> terrainTranslation (new osg::PositionAttitudeTransform);
	
	terrainTranslation->setPosition(osg::Vec3f(0,0,-1.8));
	// Create transformation node
	osg::ref_ptr<osg::MatrixTransform> terrainScaleMat (new osg::MatrixTransform);

	// Scale matrix
	osg::Matrix terrainScaleMatrix;
	terrainScaleMatrix.makeScale(osg::Vec3f(0.005f,0.005f,0.005f));

	//Loading the terrain node
	osg::ref_ptr<osg::Node> terrainNode (osgDB::readNodeFile("terrain3.3ds"));
	//Set transformation node parameters
	terrainScaleMat->setMatrix(terrainScaleMatrix);

	osg::ref_ptr<osg::PositionAttitudeTransform> translationPlane1 (new osg::PositionAttitudeTransform);
   	osg::ref_ptr<osg::Geode> geodePlane1 (new osg::Geode);
	osg::ref_ptr<osg::Box> myPlane1 (new osg::Box(osg::Vec3f(),0.01,8,8));
	osg::ref_ptr<osg::ShapeDrawable> drawablePlane1 (new osg::ShapeDrawable(myPlane1.get()));
	geodePlane1->addDrawable(drawablePlane1.get());
	translationPlane1->setPosition(osg::Vec3f(-2,0,0));
	translationPlane1->addChild(geodePlane1.get());

	osg::ref_ptr<osg::PositionAttitudeTransform> translationPlane2 (new osg::PositionAttitudeTransform);
   	osg::ref_ptr<osg::Geode> geodePlane2 (new osg::Geode);
	osg::ref_ptr<osg::Box> myPlane2 (new osg::Box(osg::Vec3f(),0.01,8,8));
	osg::ref_ptr<osg::ShapeDrawable> drawablePlane2 (new osg::ShapeDrawable(myPlane2.get()));
	geodePlane2->addDrawable(drawablePlane2.get());
	translationPlane2->setPosition(osg::Vec3f(2,0,0));
	translationPlane2->addChild(geodePlane2.get());

	osg::ref_ptr<osg::PositionAttitudeTransform> translationPlane3 (new osg::PositionAttitudeTransform);
   	osg::ref_ptr<osg::Geode> geodePlane3 (new osg::Geode);
	osg::ref_ptr<osg::Box> myPlane3 (new osg::Box(osg::Vec3f(),8,0.01,8));
	osg::ref_ptr<osg::ShapeDrawable> drawablePlane3 (new osg::ShapeDrawable(myPlane3.get()));
	geodePlane3->addDrawable(drawablePlane3.get());
	translationPlane3->setPosition(osg::Vec3f(0,2,0));
	translationPlane3->addChild(geodePlane3.get());

	
	osg::ref_ptr<osg::PositionAttitudeTransform> translationPlane4 (new osg::PositionAttitudeTransform);
   	osg::ref_ptr<osg::Geode> geodePlane4 (new osg::Geode);
	osg::ref_ptr<osg::Box> myPlane4 (new osg::Box(osg::Vec3f(),8,8,0.01));
	osg::ref_ptr<osg::ShapeDrawable> drawablePlane4 (new osg::ShapeDrawable(myPlane4.get()));
	geodePlane4->addDrawable(drawablePlane4.get());
	translationPlane4->setPosition(osg::Vec3f(0,0,4));
	translationPlane4->addChild(geodePlane4.get());

	
	osg::ref_ptr<osg::Material> material (new osg::Material);

	//Setting material 1 - capsule
	material->setAmbient(osg::Material::Face::FRONT_AND_BACK,osg::Vec4(0,0,0.8,1));
	material->setDiffuse(osg::Material::Face::FRONT_AND_BACK,osg::Vec4(0,0,0.8,1));
	material->setSpecular(osg::Material::Face::FRONT_AND_BACK,osg::Vec4(0,0,0.8,1));
	material->setEmission(osg::Material::Face::FRONT_AND_BACK,osg::Vec4(0,0,0,0));
	material->setShininess(osg::Material::Face::FRONT_AND_BACK, 0);
	
	osg::ref_ptr<osg::StateSet> nodeStateSet1 ( geodePlane1->getOrCreateStateSet() );
	osg::ref_ptr<osg::StateSet> nodeStateSet2 ( geodePlane2->getOrCreateStateSet() );
	osg::ref_ptr<osg::StateSet> nodeStateSet3 ( geodePlane3->getOrCreateStateSet() );
	osg::ref_ptr<osg::StateSet> nodeStateSet4 ( geodePlane4->getOrCreateStateSet() );
	
	nodeStateSet1->setAttribute(material);
	nodeStateSet2->setAttribute(material);
	nodeStateSet3->setAttribute(material);
	nodeStateSet4->setAttribute(material);

/* MASTER CUBE */

	osg::ref_ptr<osg::Group> cube = createCube();
	
/* LIGHTING */
	
	//Create nodes
	osg::ref_ptr<osg::Group> lightGroup0 (new osg::Group);
	osg::ref_ptr<osg::LightSource> lightSource0 = new osg::LightSource;

	//Create a local light
	osg::Vec4f lightPosition0(0,-2,3,0);
	
	osg::ref_ptr<osg::Light> myLight0 = new osg::Light;
	myLight0->setLightNum(0);
	myLight0->setPosition(lightPosition0);
	myLight0->setDiffuse(osg::Vec4f(1,1,1,1));
	myLight0->setAmbient(osg::Vec4f(0.3,0.3,0.3,1));
	myLight0->setSpecular(osg::Vec4f(1,0,0,0));

	//Set light source parameters
	lightSource0->setLight(myLight0.get());

	//Add to light source group
	lightGroup0->addChild(lightSource0.get());

	// Allumage des lumières
	rootStateSet->setMode(GL_LIGHT0, osg::StateAttribute::ON);

/* KEYBOARD INPUT */
	
 	//Stats Event Handler s key
	viewer.addEventHandler(new osgViewer::StatsHandler);

	//Windows size handler
	viewer.addEventHandler(new osgViewer::WindowSizeHandler);
	
	// add the state manipulator
    viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()));

/* SCENE GRAPH*/

	terrainScaleMat->addChild(terrainNode);
	terrainTranslation->addChild(terrainScaleMat.get());
	root->addChild(cube.get());
	root->addChild(lightGroup0.get());
	root->addChild(terrainTranslation.get());
	root->addChild(translationPlane1.get());
	root->addChild(translationPlane2.get());
	root->addChild(translationPlane3.get());
	root->addChild(translationPlane4.get());


	// Set the scene data
	viewer.setSceneData(root.get()); 

/* START VIEWER */

	//The viewer.run() method starts the threads and the traversals.
	return(viewer.run());
}


osg::Vec3f Cube::getSubCubePosition(int i, int j,int k) {
	float x = (float)(2*i)/n - 1;
	float y = (float)(2*j)/n - 1;
	float z = (float)(2*k)/n - 1;
	osg::Vec3f* pos = new osg::Vec3f(x,y,z);
	return *pos;
}

osg::ref_ptr<osg::Node> Cube::createSubCube(int i, int j,int k) {
	osg::ref_ptr<osg::PositionAttitudeTransform> translationSubCube (new osg::PositionAttitudeTransform);
   	osg::ref_ptr<osg::Geode> geodeSubCube (new osg::Geode);
	osg::ref_ptr<osg::Box> mySubCube (new osg::Box(osg::Vec3f(),2.0/n));
	osg::ref_ptr<osg::ShapeDrawable> drawableSubCube (new osg::ShapeDrawable(mySubCube.get()));
	geodeSubCube->addDrawable(drawableSubCube.get());


	translationSubCube->setPosition(getSubCubePosition(i,j,k));
	translationSubCube->addChild(geodeSubCube.get());
	return translationSubCube.get();
}

osg::ref_ptr<osg::Group> Cube::createCube() {
	osg::ref_ptr<osg::Group> cube (new osg::Group);   
	osg::PolygonMode * polygonMode = new osg::PolygonMode;
    polygonMode->setMode( osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::POINT);
    osg::ref_ptr<osg::StateSet> stateSet (cube->getOrCreateStateSet());
    stateSet->setAttributeAndModes(polygonMode,osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				cube->addChild(createSubCube(i,j,k));
			}
		}
	}

	return cube;
}