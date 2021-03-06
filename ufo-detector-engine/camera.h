/*
 * UFO Detector | www.UFOID.net
 *
 * Copyright (C) 2016 UFOID
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "camerainfo.h"
#include <opencv2/highgui/highgui.hpp>
#include <mutex>
#include <thread>
#include <atomic>
#include <memory>
#include <QObject>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <QDebug>

/**
 * @brief Main camera class to handle reading of frames from multiple threads
 *
 * @todo add setResolution(width, height) method to apply resolution change on-the-fly
 */
class Camera : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Camera constructor. You need to call Camera::init() to actually start using the camera.
     * @param index camera index as used by OpenCV
     * @param width camera frame width
     * @param height camera frame height
     * Note that given resolution (width * height) may not be supported, but normally
     * you will get nearest supported resolution anyway.
     */
    Camera(int index, int width, int height);

    /**
     * @brief Initialize and open camera.
     * @return true if initialization was successful, false if it failed
     */
    bool init();

    /**
     * @brief Whether the camera is initialized.
     * @return true if camera is initialized, false if not
     */
    bool isInitialized();

    /**
     * @brief Stop and close camera.
     */
    void release();

    /**
     * @brief Get the current/newest frame from camera.
     * @return
     */
    cv::Mat getWebcamFrame();
    bool isWebcamOpen();

    /**
     * @brief Camera index.
     * @return
     */
    int index();

    /**
     * @brief Run web camera resolution query.
     * @return
     */
    bool queryAvailableResolutions();

    /**
     * @brief List of available web camera resolutions.
     * @return list of resolutions, or an empty list if queryAvailableResolutions() was not called previously
     */
    QList<QSize> availableResolutions();

    /**
     * @brief List of known aspect ratios. List may grow on queryAvailableResolutions().
     * @return
     */
    QList<int> knownAspectRatios();

#ifndef _UNIT_TEST_
private:
#endif
    int m_index;    ///< camera index as used by OpenCV
    int m_width;
    int m_height;
    cv::VideoCapture* m_webcam;
    cv::Mat videoFrame;
    std::mutex mutex;
    CameraInfo* m_cameraInfo;
    bool m_initialized;     ///< whether camera is initialized or not

signals:
    /**
     * @brief Emitted when querying available resolutions progresses.
     * @param percent percent of querying ready
     */
    void queryProgressChanged(int percent);

};

#endif // CAMERA_H
