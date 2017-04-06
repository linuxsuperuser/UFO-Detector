pipeline {
  agent any
  stages {
    stage('build') {
	wrap([$class: 'Xvfb']) {
        sh '''qmake  ui-qt/Detector.pro -spec linux-g++
make'''
      
	  }
    }
  }
}
