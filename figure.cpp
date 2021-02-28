#include "figure.h"

Figure::Figure()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);

    setBrush(brush);
}

Figure::~Figure()
{

}

void Figure::rangeCheckNew(int number)
{
    assert(number >= 0 && number <= getSize());

    /*
    if (number < 0 || number > getSize())
        throw ("Out of range");
    */
}

void Figure::rangeCheckExist(int number)
{
    assert(number >= 0 && number < getSize());

    /*
    if (number < 0 || number >= getSize())
        throw ("Out of range");
    */
}

void Figure::addCoord(double x, double y)
{
    QPointF newCoord(x, y);
    addCoord(newCoord, coords.size());
}

void Figure::addCoord(double x, double y, int number)
{
    QPointF newCoord(x, y);
    addCoord(newCoord, number);
}

void Figure::addCoord(QPointF coord)
{
    addCoord(coord, coords.size());
}

void Figure::addCoord(QPointF coord, int number)
{
    rangeCheckNew(number);

    if (checkCoord(coord) == false)
        coords.insert(number, coord);
}

void Figure::deleteCoord(double x, double y)
{
    QPointF coord(x, y);
    deleteCoord(coord);
}

void Figure::deleteCoord(QPointF coord)
{
    if (checkCoord(coord))
        deleteCoord(getCoord(coord));
}

void Figure::deleteCoord(int number)
{
    rangeCheckExist(number);

    coords.remove(number);
}

bool Figure::checkCoord(double x, double y)
{
    QPointF coord(x, y);
    return checkCoord(coord);
}

bool Figure::checkCoord(QPointF coord)
{
    for (int i = 0; i < getSize(); i++)
        if (coord == coords[i])
            return true;

    return false;
}

int Figure::getCoord(double x, double y)
{
    QPointF coord(x, y);
    return getCoord(coord);
}

int Figure::getCoord(QPointF coord)
{
    for (int i = 0; i < getSize(); i++)
        if (coords[i] == coord)
            return i;

    return -1;
}

int Figure::getSize()
{
    return coords.size();
}

void Figure::changeCoord(int number, double newX, double newY)
{
    QPointF coord(newX, newY);
    changeCoord(number, coord);
}

void Figure::changeCoord(int number, QPointF newCoord)
{
    rangeCheckExist(number);

    coords[number] = newCoord;
}

void Figure::changeCoord(double oldX, double oldY, double newX, double newY)
{
    QPointF oldCoord(oldX, oldY);
    QPointF newCoord(newX, newY);
    changeCoord(oldCoord, newCoord);
}

void Figure::changeCoord(QPointF oldCoord, QPointF newCoord)
{
    int index = getCoord(oldCoord);
    if (index != -1)
        coords[index] = newCoord;
}

QVector<QPointF> Figure::getCoords()
{
    return coords;
}

QVector<QPointF> Figure::getStartingCoords()
{
    return startingCoords;
}

void Figure::updateSCoords()
{
    startingCoords = coords;
}

QPointF &Figure::operator[](const int index)
{
    rangeCheckExist(index);

    return coords[index];
}
