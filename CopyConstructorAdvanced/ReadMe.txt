========================================================================
    CONSOLE APPLICATION : CopyConstructorAdvanced Project Overview
========================================================================
////////////////////////////////////////////////////////////////////////

GOAL:
This project simply proves that copy constructor is called for parameters that are not reference.

////////////////////////////////////////////////////////////////////////
========================================================================

Summary of files that this project consists of:

SOURCE FILES:		----------------------------------------------------

CopyConstructorAdvanced.cpp
    This is the main function source file.

healthy_copy_class.h and healthy_copy_class.cpp
	This class copies the data it contains correctly in its copy constructor.
	Also most of more complex tests (like copy elision) are written for this class.

AUTO GENERATED FILES:	------------------------------------------------

CopyConstructorAdvanced.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

CopyConstructorAdvanced.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named CopyConstructorAdvanced.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
