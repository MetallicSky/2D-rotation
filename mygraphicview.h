#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QVector>
#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>



#include "figure.h"
#include "dot.h"

class MyGraphicView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicView(QWidget *parent = 0);
    ~MyGraphicView();

    void setAutoRepeat(bool activate);
    void setDeg(int deg);
    void restart();


signals:

    void dotChanged();

private slots:

private:
    QGraphicsScene *scene;
    Figure *arrow;
    Dot *dot;
    bool autoRepeat;

    void mousePressEvent(QMouseEvent *event);


private:

};

#endif // MYGRAPHICVIEW_H
