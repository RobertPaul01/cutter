#include <QDebug>
#include "cutter.h"
#include "analthread.h"

AnalThread::AnalThread(QWidget *parent) :
    QThread(parent),
    core(nullptr),
    level(2)
{
}

AnalThread::~AnalThread()
{
    if (isRunning())
    {
        quit();
        wait();
    }
}

void AnalThread::start(CutterCore *core, int level, QList<QString> advanced)
{
    this->core = core;
    this->level = level;
    this->advanced = advanced;

    QThread::start();
}

// run() will be called when a thread starts
void AnalThread::run()
{
    //qDebug() << "Anal level: " << this->level;
    core->analyze(this->level, this->advanced);
}
