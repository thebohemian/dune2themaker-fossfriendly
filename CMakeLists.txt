cmake_minimum_required(VERSION 2.8)

PROJECT(DUNE2THEMAKER)
SET( PACKAGE "dune2themaker" )
#SET( CMAKE_MODULE_PATH ${DOONLUNACY_SOURCE_DIR}/cmake/modules )

SET(VERSION "0.1")

# Deal with finding allegro 4.2
IF(UNIX)
        FIND_PROGRAM(ALLEGROCONFIG "allegro-config"
                     DOC "Full path to the allegro-config command")

        IF(NOT ALLEGROCONFIG)
                MESSAGE(SEND_ERROR "Error: allegro-config was not found!")
        ELSE(NOT ALLEGROCONFIG)
                MESSAGE(STATUS "Found allegro-config: ${ALLEGROCONFIG}")
        ENDIF(NOT ALLEGROCONFIG)

	# get allegro include flags and other compile-time flags from allegro-config
	EXECUTE_PROCESS(COMMAND ${ALLEGROCONFIG} --cflags
	             RESULT_VARIABLE EXITCODE
	             ERROR_VARIABLE STDERR
	             OUTPUT_VARIABLE ALLEGRO_CFLAGS
	             OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_STRIP_TRAILING_WHITESPACE)

	IF(NOT EXITCODE EQUAL 0)
		MESSAGE(SEND_ERROR "Error: `${ALLEGROCONFIG} --cflags' failed with status: ${EXITCODE}")
		MESSAGE(SEND_ERROR "  stderr: ${STDERR}")
		MESSAGE(SEND_ERROR "  stdout: ${ALLEGRO_CFLAGS}")
	ELSEIF(NOT ALLEGRO_CFLAGS)
		MESSAGE(SEND_ERROR "Error: `${ALLEGROCONFIG} --cflags' failed to produce any output")
	ELSE(NOT EXITCODE EQUAL 0)
		MESSAGE(STATUS "Allegro CFLAGS: ${ALLEGRO_CFLAGS}")
		SET(ALLEGRO_CFLAGS ${ALLEGRO_CFLAGS} CACHE STRING "Output of `allegro-config --cflags'")
	ENDIF(NOT EXITCODE EQUAL 0)

	# get info for linking against allegro from the allegro-config command
	EXECUTE_PROCESS(COMMAND ${ALLEGROCONFIG} --libs
	             RESULT_VARIABLE EXITCODE
	             ERROR_VARIABLE STDERR
	             OUTPUT_VARIABLE ALLEGRO_LFLAGS
	             OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_STRIP_TRAILING_WHITESPACE)

	IF(NOT EXITCODE EQUAL 0)
		MESSAGE(SEND_ERROR "Error: `${ALLEGROCONFIG} --libs' failed with status: ${EXITCODE}")
		MESSAGE(SEND_ERROR "  stderr: ${STDERR}")
		MESSAGE(SEND_ERROR "  stdout: ${ALLEGRO_LFLAGS}")
	ELSEIF(NOT ALLEGRO_LFLAGS)
		MESSAGE(SEND_ERROR "Error: `${ALLEGROCONFIG} --libs' failed to produce any output")
	ELSE(NOT EXITCODE EQUAL 0)
		MESSAGE(STATUS "Allegro CFLAGS: ${ALLEGRO_LFLAGS}")
		SET(ALLEGRO_LFLAGS ${ALLEGRO_LFLAGS} CACHE STRING "Output of `allegro-config --lflags'")
	ENDIF(NOT EXITCODE EQUAL 0)

ENDIF(UNIX)

# Deal with alfont
SET (ALFONT_DIR ${PROJECT_SOURCE_DIR}/dependencies/alfont_2.0.7)
SET (ALFONT_INCLUDES ${ALFONT_DIR}/include CACHE STRING "Path to alfont include directory" )
INCLUDE_DIRECTORIES ( ${ALFONT_INCLUDES} )
ADD_SUBDIRECTORY( ${ALFONT_DIR} )

# Deal with almp3
SET (ALMP3_DIR ${PROJECT_SOURCE_DIR}/dependencies/almp3)
SET (ALMP3_INCLUDES ${ALMP3_DIR}/include CACHE STRING "Path to almp3 include directory" )
INCLUDE_DIRECTORIES ( ${ALMP3_INCLUDES} )
ADD_SUBDIRECTORY( ${ALMP3_DIR} )

# Deal with fblend
SET (FBLEND_DIR ${PROJECT_SOURCE_DIR}/dependencies/fblend)
SET (FBLEND_INCLUDES ${FBLEND_DIR}/include CACHE STRING "Path to fblend include directory" )
INCLUDE_DIRECTORIES ( ${FBLEND_INCLUDES} )
ADD_SUBDIRECTORY( ${FBLEND_DIR} )

INCLUDE_DIRECTORIES ( ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include )

#SET(CPACK_PACKAGE_VERSION, "${VERSION}")
#SET(CPACK_SOURCE_IGNORE_FILES ".git" "build" ".swp$" ".*~")
#SET(CPACK_PACKAGE_NAME, "${PACKAGE}")
#SET(CPACK_SOURCE_GENERATOR "TGZ;TXZ")
#SET(CPACK_SOURCE_PACKAGE_FILE_NAME "${PACKAGE}-${VERSION}")
#INCLUDE(CPack)


SET ( MAIN_SRC
	ai.cpp
	cGame_logic.cpp
	gui.cpp
	ini.cpp
	regions.cpp
	cGame_draw.cpp
	cMentat.cpp
#	hwprof.cpp
	main.cpp
	timers.cpp
)

SET ( CONTROLS_SRC
	controls/cMouse.cpp
	controls/cGameControlsContext.cpp
	controls/cKeyboard.cpp
)

SET ( BUILDING_SRC
	building/cItemBuilder.cpp
)

SET (MENTAT_SRC
#	mentat/cBenegesMentat.cpp
	mentat/cMentatFactory.cpp
	mentat/cHarkonnenMentat.cpp
	mentat/cAtreidesMentat.cpp
	mentat/cOrdosMentat.cpp
)

SET (UPGRADE_SRC
	upgrade/cUpgradeBuilder.cpp
	upgrade/cListUpgrade.cpp
	upgrade/cBuildingListUpdater.cpp
)

SET (PLAYER_SRC
	player/cPlayerStatistics.cpp
	player/cPlayerOrdosDifficultySettings.cpp
	player/cPlayerDifficultySettings.cpp
	player/cPlayer.cpp
	player/cPlayerHarkonnenDifficultySettings.cpp
	player/cPlayerAtreidesDifficultySettings.cpp
)

SET (UTILS_SRC
	utils/cScreenResolution.cpp
	utils/cLog.cpp
	utils/cTimeManager.cpp
	utils/cHitpointCalculator.cpp
	utils/cStructureUtils.cpp
	utils/cSeedMap.cpp
	utils/cSimpleCalculator.cpp
	utils/cCellCalculator.cpp
	utils/cPlayerUtils.cpp
	utils/cMapUtils.cpp
	utils/cListUtils.cpp
	utils/cUpgradeUtils.cpp
	utils/cBestScreenResolutionFinder.cpp
	utils/cSeedMapGenerator.cpp
	utils/common.cpp
	utils/cSoundPlayer.cpp
	utils/cMouseUtils.cpp
	utils/d2tm_math.cpp
)

SET (SIDEBAR_SRC
	sidebar/cBuildingListFactory.cpp
	sidebar/cBuildingList.cpp
	sidebar/cBuildingListItem.cpp
	sidebar/cSideBarFactory.cpp
	sidebar/cSideBar.cpp
)

SET (MAP_SRC
	map/cMapEditor.cpp
	map/cRandomMapGenerator.cpp
	map/cMapCamera.cpp
	map/cMap.cpp
)

SET (GAMEOBJECTS_SRC
	gameobjects/units/cUnitFactory.cpp
	gameobjects/units/cUnit.cpp
	gameobjects/units/cAbstractUnit.cpp
	gameobjects/units/cUnitUtils.cpp
	gameobjects/projectiles/bullet.cpp
	gameobjects/structures/cIx.cpp
	gameobjects/structures/cGunTurret.cpp
	gameobjects/structures/cRefinery.cpp
	gameobjects/structures/cWor.cpp
	gameobjects/structures/cAbstractStructure.cpp
	gameobjects/structures/cConstYard.cpp
	gameobjects/structures/cOutPost.cpp
	gameobjects/structures/cOrderProcesser.cpp
	gameobjects/structures/cStarPort.cpp
	gameobjects/structures/cPalace.cpp
	gameobjects/structures/cLightFactory.cpp
	gameobjects/structures/cWindTrap.cpp
	gameobjects/structures/cStructurePlacer.cpp
	gameobjects/structures/cBarracks.cpp
	gameobjects/structures/cSpiceSilo.cpp
	gameobjects/structures/cRocketTurret.cpp
	gameobjects/structures/cRepairFacility.cpp
	gameobjects/structures/cStructureFactory.cpp
	gameobjects/structures/cHighTech.cpp
	gameobjects/structures/cHeavyFactory.cpp
	gameobjects/particles/cParticle.cpp
	gameobjects/cGameObject.cpp
)

SET (MANAGERS_SRC
	managers/cDrawManager.cpp
	managers/cKeyboardManager.cpp
	managers/cInteractionManager.cpp
)

SET ( DRAWERS_SRC
	drawers/cMapDrawer.cpp
	drawers/cParticleDrawer.cpp
	drawers/cMouseDrawer.cpp
	drawers/cMiniMapDrawer.cpp
	drawers/cOrderDrawer.cpp
	drawers/cAllegroDrawer.cpp
	drawers/cStructureDrawer.cpp
	drawers/cSideBarDrawer.cpp
	drawers/cMessageDrawer.cpp
	drawers/cPlaceItDrawer.cpp
	drawers/cTextDrawer.cpp
	drawers/cUpgradeDrawer.cpp
	drawers/cBuildingListDrawer.cpp
	drawers/cUnitDrawer.cpp
	drawers/cMessageBarDrawer.cpp
	drawers/CreditsDrawer.cpp
)

SET ( GUI_SRC
	gui/Shape.cpp
	gui/cMessageBar.cpp
	gui/cTextWriter.cpp
	gui/cMouseToolTip.cpp
)

ADD_EXECUTABLE ( dune2themaker
	${MAIN_SRC}
	${GUI_SRC}
	${DRAWERS_SRC}
	${MANAGERS_SRC}
	${GAMEOBJECTS_SRC}
	${MAP_SRC}
	${SIDEBAR_SRC}
	${UTILS_SRC}
	${PLAYER_SRC}
	${CONTROLS_SRC}
	${BUILDING_SRC}
	${MENTAT_SRC}
	${UPGRADE_SRC}
)

TARGET_LINK_LIBRARIES ( dune2themaker alfont almp3 fblend )

SET_TARGET_PROPERTIES( dune2themaker
	PROPERTIES
		COMPILE_FLAGS "${ALLEGRO_CFLAGS} -DUNIX"
		LINK_FLAGS "${ALLEGRO_LFLAGS}"
)

