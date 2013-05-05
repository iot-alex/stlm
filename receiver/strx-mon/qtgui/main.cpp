/*
 * Copyright (C) 2013 Alexandru Csete, OZ9AEC
 *
 * Strx is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * Strx is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#include <iostream>

#include <Ice/Ice.h>
#include <QtGui/QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Ice::CommunicatorPtr ice_com;
    Ice::ObjectPrx       ice_prx;

    try
    {
        // Get proxy object
        ice_com = Ice::initialize(argc, argv);
        ice_prx = ice_com->stringToProxy("gnuradio:tcp -h localhost -p 43243");
    }
    catch (const Ice::Exception& ex)
    {
        std::cerr << ex << std::endl;
        return 1;
    }

    QApplication a(argc, argv);
    MainWindow w(ice_prx);
    w.show();
    
    return a.exec();
}
