/*
 * Alzachat main file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
        QCoreApplication a(argc, argv);
        qDebug() << "Hello World";
        return QCoreApplication::exec();
}
