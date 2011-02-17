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

INCLUDE_DIRECTORIES ( ${PROJECT_SOURCE_DIR}/src/include ${PROJECT_SOURCE_DIR}/src )

#SET(CPACK_PACKAGE_VERSION, "${VERSION}")
#SET(CPACK_SOURCE_IGNORE_FILES ".git" "build" ".swp$" ".*~")
#SET(CPACK_PACKAGE_NAME, "${PACKAGE}")
#SET(CPACK_SOURCE_GENERATOR "TGZ;TXZ")
#SET(CPACK_SOURCE_PACKAGE_FILE_NAME "${PACKAGE}-${VERSION}")
#INCLUDE(CPack)


SET ( MAIN_SRC
	src/ai.cpp
	src/cGame_logic.cpp
	src/gui.cpp
	src/ini.cpp
	src/regions.cpp
	src/cGame_draw.cpp
	src/cMentat.cpp
	src/main.cpp
	src/timers.cpp
)

SET ( CONTROLS_SRC
	src/controls/cMouse.cpp
	src/controls/cGameControlsContext.cpp
	src/controls/cKeyboard.cpp
)

SET ( BUILDING_SRC
	src/building/cItemBuilder.cpp
)

SET (MENTAT_SRC
#	src/mentat/cBenegesMentat.cpp
	src/mentat/cMentatFactory.cpp
	src/mentat/cHarkonnenMentat.cpp
	src/mentat/cAtreidesMentat.cpp
	src/mentat/cOrdosMentat.cpp
)

SET (UPGRADE_SRC
	src/upgrade/cUpgradeBuilder.cpp
	src/upgrade/cListUpgrade.cpp
	src/upgrade/cBuildingListUpdater.cpp
)

SET (PLAYER_SRC
	src/player/cPlayerStatistics.cpp
	src/player/cPlayerOrdosDifficultySettings.cpp
	src/player/cPlayerDifficultySettings.cpp
	src/player/cPlayer.cpp
	src/player/cPlayerHarkonnenDifficultySettings.cpp
	src/player/cPlayerAtreidesDifficultySettings.cpp
)

SET (UTILS_SRC
	src/utils/cScreenResolution.cpp
	src/utils/cLog.cpp
	src/utils/cTimeManager.cpp
	src/utils/cHitpointCalculator.cpp
	src/utils/cStructureUtils.cpp
	src/utils/cSeedMap.cpp
	src/utils/cSimpleCalculator.cpp
	src/utils/cCellCalculator.cpp
	src/utils/cPlayerUtils.cpp
	src/utils/cMapUtils.cpp
	src/utils/cListUtils.cpp
	src/utils/cUpgradeUtils.cpp
	src/utils/cBestScreenResolutionFinder.cpp
	src/utils/cSeedMapGenerator.cpp
	src/utils/common.cpp
	src/utils/cSoundPlayer.cpp
	src/utils/cMouseUtils.cpp
	src/utils/d2tm_math.cpp
)

SET (SIDEBAR_SRC
	src/sidebar/cBuildingListFactory.cpp
	src/sidebar/cBuildingList.cpp
	src/sidebar/cBuildingListItem.cpp
	src/sidebar/cSideBarFactory.cpp
	src/sidebar/cSideBar.cpp
)

SET (MAP_SRC
	src/map/cMapEditor.cpp
	src/map/cRandomMapGenerator.cpp
	src/map/cMapCamera.cpp
	src/map/cMap.cpp
)

SET (GAMEOBJECTS_UNITS_SRC
	src/gameobjects/units/cUnitFactory.cpp
	src/gameobjects/units/cUnit.cpp
	src/gameobjects/units/cAbstractUnit.cpp
	src/gameobjects/units/cUnitUtils.cpp
)

SET (GAMEOBJECTS_PROJECTILES_SRC
	src/gameobjects/projectiles/bullet.cpp
)

SET (GAMEOBJECTS_STRUCTURES_SRC
	src/gameobjects/structures/cIx.cpp
	src/gameobjects/structures/cGunTurret.cpp
	src/gameobjects/structures/cRefinery.cpp
	src/gameobjects/structures/cWor.cpp
	src/gameobjects/structures/cAbstractStructure.cpp
	src/gameobjects/structures/cConstYard.cpp
	src/gameobjects/structures/cOutPost.cpp
	src/gameobjects/structures/cOrderProcesser.cpp
	src/gameobjects/structures/cStarPort.cpp
	src/gameobjects/structures/cPalace.cpp
	src/gameobjects/structures/cLightFactory.cpp
	src/gameobjects/structures/cWindTrap.cpp
	src/gameobjects/structures/cStructurePlacer.cpp
	src/gameobjects/structures/cBarracks.cpp
	src/gameobjects/structures/cSpiceSilo.cpp
	src/gameobjects/structures/cRocketTurret.cpp
	src/gameobjects/structures/cRepairFacility.cpp
	src/gameobjects/structures/cStructureFactory.cpp
	src/gameobjects/structures/cHighTech.cpp
	src/gameobjects/structures/cHeavyFactory.cpp
	src/gameobjects/particles/cParticle.cpp
	src/gameobjects/cGameObject.cpp
)

SET (MANAGERS_SRC
	src/managers/cDrawManager.cpp
	src/managers/cKeyboardManager.cpp
	src/managers/cInteractionManager.cpp
)

SET ( DRAWERS_SRC
	src/drawers/cMapDrawer.cpp
	src/drawers/cParticleDrawer.cpp
	src/drawers/cMouseDrawer.cpp
	src/drawers/cMiniMapDrawer.cpp
	src/drawers/cOrderDrawer.cpp
	src/drawers/cAllegroDrawer.cpp
	src/drawers/cStructureDrawer.cpp
	src/drawers/cSideBarDrawer.cpp
	src/drawers/cMessageDrawer.cpp
	src/drawers/cPlaceItDrawer.cpp
	src/drawers/cTextDrawer.cpp
	src/drawers/cUpgradeDrawer.cpp
	src/drawers/cBuildingListDrawer.cpp
	src/drawers/cUnitDrawer.cpp
	src/drawers/cMessageBarDrawer.cpp
	src/drawers/CreditsDrawer.cpp
)

SET ( GUI_SRC
	src/gui/Shape.cpp
	src/gui/cMessageBar.cpp
	src/gui/cTextWriter.cpp
	src/gui/cMouseToolTip.cpp
)

ADD_EXECUTABLE ( dune2themaker
	${MAIN_SRC}
	${GUI_SRC}
	${DRAWERS_SRC}
	${MANAGERS_SRC}
	${GAMEOBJECTS_UNITS_SRC}
	${GAMEOBJECTS_PROJECTILES_SRC}
	${GAMEOBJECTS_STRUCTURES_SRC}
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


