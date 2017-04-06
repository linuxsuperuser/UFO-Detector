pipeline {
  agent any
  stages {
    stage('build') {
		node {
			wrap([$class: 'Xvfb']) {
			     steps {
						sh '''qmake  ui-qt/Detector.pro -spec linux-g++
						make'''
				}
			}
		} 
    }
  }
}
