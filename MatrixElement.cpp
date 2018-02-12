//
// Created by sam on 2/11/18.
//

#include "MatrixElement.h"
#include <QPainter>
#include <QtWidgets/QtWidgets>
#include <Headers/GameWindow.h>
#include <QtWidgets/QWidget>

MatrixElement::MatrixElement() {
    isUsable=0;
    elementMode=0;
}

QRectF MatrixElement::boundingRect() const
{
    return QRectF(0,0,50,50);
}
QPainterPath MatrixElement::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 50, 50);
    return path;
}
void MatrixElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
    painter->setBrush(Qt::lightGray);
    //painter->drawEllipse(-10, -20, 20, 40);
    painter->drawRect(0,0,50,50);
    if(elementMode==WHITE){
        painter->setBrush(Qt::white);
        painter->drawEllipse(0,0,50,50);
    }else if(elementMode==BLACK){
        painter->setBrush(Qt::black);
        painter->drawEllipse(0,0,50,50);
    }
    if(isUsable){
        painter->setPen(Qt::darkRed);
        painter->drawEllipse(0,0,50,50);
    }
    // Eyes
    //painter->setBrush(Qt::white);
    //painter->setPen(Qt::yellow);
    //painter->drawEllipse(0, 0, 50, 50);
}
void MatrixElement::advance(int step)
{
    if (!step) return;
    if(isUsable) setAcceptHoverEvents(1);
    else setAcceptHoverEvents(0);
}
//hover
void MatrixElement::mouseMoveEvent(QMouseEvent *theEvent) {
    qDebug()<<theEvent->x()<<":"<<theEvent->y();
}
void MatrixElement::mousePressEvent(QGraphicsSceneMouseEvent *theEvent) {
    //qDebug()<<"clicked:"<<theEvent->pos()<<isUsable;
    //qDebug()<<this;
    emit clickedOn(xPos,yPos);
}