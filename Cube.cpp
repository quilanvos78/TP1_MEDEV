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
	osgViewer::Viewer viewer ;

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

/* MASTER CUBE */

	osg::ref_ptr<osg::Group> cube = createCube();
	
/* LIGHTING */
	
	//Create nodes
	osg::ref_ptr<osg::Group> lightGroup0 (new osg::Group);
	osg::ref_ptr<osg::LightSource> lightSource0 = new osg::LightSource;

	//Create a local light
	osg::Vec4f lightPosition0(0,2,0,0);
	
	osg::ref_ptr<osg::Light> myLight0 = new osg::Light;
	myLight0->setLightNum(0);
	myLight0->setPosition(lightPosition0);
	myLight0->setDiffuse(osg::Vec4f(1,1,1,1));
	myLight0->setAmbient(osg::Vec4f(0.4,0.4,0.4,1));
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

	
   	osg::ref_ptr<osg::Geode> geodeSubCube (new osg::Geode);
	osg::ref_ptr<osg::Box> mySubCube (new osg::Box(osg::Vec3f(),10));
	osg::ref_ptr<osg::ShapeDrawable> drawableSubCube (new osg::ShapeDrawable(mySubCube.get()));
	geodeSubCube->addDrawable(drawableSubCube.get());


	//root->addChild(geodeSubCube.get());

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