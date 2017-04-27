QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage


TEMPLATE = subdirs

SUBDIRS = \
    testCameraInfo \
    testConfig \
    testRecorder \
    testActualDetector \
    testVideoCodecSupportInfo \
    testVideoBuffer \
    testDataManager
    
skip {
      SUBDIRS -=  testCameraInfo
    }

LIBS += -lgcov

# borrowed from https://github.com/KDAB/KDSoap/blob/master/unittests/unittests.pro (project is also LGPL)
test.target=test
unix:!macx {
    LIB_PATH=$${TOP_BUILD_DIR}/lib:\$\$LD_LIBRARY_PATH
    test.commands=for d in $${SUBDIRS}; do origdir="\$$PWD" && cd "\$$d" && LD_LIBRARY_PATH=$$LIB_PATH && $(MAKE) test && cd "\$$origdir" || exit 1; done
}
unix:macx {
    LIB_PATH=$${TOP_BUILD_DIR}/lib:\$\$DYLD_LIBRARY_PATH
    test.commands=for d in $${SUBDIRS}; do ( cd "\$$d" && export DYLD_LIBRARY_PATH=$$LIB_PATH && $(MAKE) test ) || exit 1; done
}
win32 {
    WIN_BINDIR=
    debug_and_release {
        WIN_BINDIR=release
    }

    RUNTEST=$${TOP_SOURCE_DIR}/unittests/runTest.bat
    RUNTEST=$$replace(RUNTEST, /, \\)
    LIB_PATH=$$TOP_BUILD_DIR/lib
    LIB_PATH=$$replace(LIB_PATH, /, \\)
    test.commands=for %d in ($${SUBDIRS}); do $$RUNTEST $$LIB_PATH "%d" $$WIN_BINDIR || exit 1; done
}
test.depends = first
QMAKE_EXTRA_TARGETS += test
