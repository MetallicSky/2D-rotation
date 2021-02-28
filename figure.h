#ifndef FIGURE_H
#define FIGURE_H


#include <QGraphicsItem>
#include <QPainter>

class Figure : public QGraphicsPolygonItem
{
    QVector<QPointF> coords;
    QVector<QPointF> startingCoords;

    void rangeCheckNew(int number);
    void rangeCheckExist(int number);

public:

    Figure();
    ~Figure();

    void addCoord(double x, double y);
    void addCoord(double x, double y, int number);
    void addCoord(QPointF coord);
    void addCoord(QPointF coord, int number);

    void deleteCoord(double x, double y);
    void deleteCoord(QPointF coord);
    void deleteCoord(int number);

    bool checkCoord(double x, double y);
    bool checkCoord(QPointF coord);

    int getCoord(double x, double y);
    int getCoord(QPointF coord);

    int getSize();

    void changeCoord(int number, double newX, double newY);
    void changeCoord(int number, QPointF newCoord);
    void changeCoord(double oldX, double oldY, double newX, double newY);
    void changeCoord(QPointF oldCoord, QPointF newCoord);

    QVector<QPointF> getCoords();
    QVector<QPointF> getStartingCoords();

    void updateSCoords();

    QPointF& operator[] (const int index);
};

#endif // FIGURE_H
