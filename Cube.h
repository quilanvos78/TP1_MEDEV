#pragma once

// Base
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>
#include <osg/PositionAttitudeTransform>
#include <osg/Material>
#include <osg/StateSet>
#include <osg/MatrixTransform>
#include <osg/Geometry>
#include <osgDB/ReadFile>

// Keyboard input
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>

// Other
#include <iostream>


class Cube {
private:
	int n;
	osg::ref_ptr<osg::Group> root;
	osg::Vec3f getSubCubePosition(int i,int j,int k);
	osg::ref_ptr<osg::Node> createSubCube(int i,int j,int k);
	osg::ref_ptr<osg::Group> createCube();
public:
	Cube(int _n);
	int init();
	int getSize() { return n; }
};