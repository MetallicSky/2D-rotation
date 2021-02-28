#include "mygraphicview.h"

MyGraphicView::MyGraphicView(QWidget *parent)
    : QGraphicsView(parent)
{
    this->setRenderHint(QPainter::Antialiasing);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->setAlignment(Qt::AlignCenter);
    //this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene(this);
    this->setScene(scene);
    scene->setSceneRect(0, 0, 280, 280);
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    arrow = new Figure();
    scene->addItem(arrow);

    dot = new Dot();
    scene->addItem(dot);

    dot->setPos(135, 75);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    dot->setBrush(brush);

    QVector<QPointF> dotPoints;
    dotPoints << QPoint(0,0)
              << QPointF(10, 0)
              << QPointF(10, 10)
              << QPointF(0, 10);
    dot->setPolygon(dotPoints);



    autoRepeat = false;
    restart();

}

MyGraphicView::~MyGraphicView()
{

}

void MyGraphicView::setAutoRepeat(bool activate)
{
    autoRepeat = activate;
}

void MyGraphicView::setDeg(int deg)
{
    double d(deg);
    double radians = qDegreesToRadians(d);

    double dotX = dot->pos().x() + 5;
    double dotY = dot->pos().y() + 5;

    QVector<QPointF> originalArrow = arrow->getStartingCoords();

    for (int i = 0; i < arrow->getSize(); i++)
    {
        double oldX = originalArrow[i].x();
        double oldY = originalArrow[i].y();

        double newX = (oldX - dotX) * qCos(radians) - (oldY - dotY) * qSin(radians) + dotX;
        double newY = (oldX - dotX) * qSin(radians) + (oldY - dotY) * qCos(radians) + dotY;

        arrow->changeCoord(i, newX, newY);
    }
    scene->removeItem(arrow);
    arrow->setPolygon(arrow->getCoords());
    scene->addItem(arrow);

}

void MyGraphicView::restart()
{
    int startingX = 120;
    int startingY = 160;
    QPointF c1(startingX, startingY);
    QPointF c2(startingX + 20, startingY - 20);
    QPointF c3(startingX + 40, startingY);
    QPointF c4(startingX + 20, startingY - 40);

    if (arrow->getSize() == 0)
    {
        arrow->addCoord(c1);
        arrow->addCoord(c2);
        arrow->addCoord(c3);
        arrow->addCoord(c4);
    }
    else
    {
        arrow->operator[](0) = c1;
        arrow->operator[](1) = c2;
        arrow->operator[](2) = c3;
        arrow->operator[](3) = c4;
    }

    arrow->setPolygon(arrow->getCoords());
    arrow->setPos(0, 0);

    arrow->updateSCoords();
}

void MyGraphicView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dot->setX(event->pos().x() - 5);
        dot->setY(event->pos().y() - 5);

        if (autoRepeat)
            restart();
        else
            arrow->updateSCoords();

        emit dotChanged();
    }
}
