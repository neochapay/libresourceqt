/*************************************************************************
This file is part of libresourceqt

Copyright (C) 2011 Nokia Corporation.

This library is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation
version 2.1 of the License.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
USA.
*************************************************************************/

#ifndef TEST_RESOURCE_SET_H
#define TEST_RESOURCE_SET_H

#include <QObject>
#include <QList>
#include <QtTest/QTest>
#include <policy/resource-set.h>

class TestResourceSet: public QObject
{
    Q_OBJECT
private:
    ResourcePolicy::Resource * resourceFromType(ResourcePolicy::ResourceType type);

    void waitForSignal(const QObject *sender, const char *signal, quint32 timeout = 1000);

public:
    TestResourceSet();
    ~TestResourceSet();

public slots:

    void handleResourcesBecameAvailable(const QList<ResourcePolicy::ResourceType> &availableResources);
    void handleResourcesGranted(const QList<ResourcePolicy::ResourceType> &grantedOptionalResources);
    void handleResourcesDenied();
    void handleResourcesReleased();
    void handleLostResources();
    void handleManagerIsUp();
    void handleUpdateOK();
    void handleResourcesReleasedByManager();
    void handleErrorCallback(quint32, const char*);

private slots:

    void testConstructor1();
    void testConstructor2();

    void testContainsSet();
    void testIdentifier();

    void testAddResource();
    void testAddResourceObject();
    void testAddResourceObjectNull();
    void testAddResourceObjectAudio();
    void testAddResourceObjectVideo();
    void testDelResource();

    void testSetAutoRelease();
    void testSetAutoReleaseNoInit();
    void testSetAlwaysReply();
    void testSetAlwaysReplyNoInit();

    void testConnectToSignals();

    void testConnectEngine();
    void testConnectEngine2();
    void testDoubleInit();

    void testAcquire();
    void testDoubleAcquire();
    void testUpdateNoInit();

    void testUninitializedRelease();
};

#endif
