/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2017  Seamly, LLC                                       *
 *                                                                         *
 *   https://github.com/fashionfreedom/seamly2d                             *
 *                                                                         *
 ***************************************************************************
 **
 **  Seamly2D is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Seamly2D is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Seamly2D.  If not, see <http://www.gnu.org/licenses/>.
 **
 **************************************************************************

 ************************************************************************
 **
 **  @file   vtoolpointfromarcandtangent.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   6 6, 2015
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2015 Seamly2D project
 **  <https://github.com/fashionfreedom/seamly2d> All Rights Reserved.
 **
 **  Seamly2D is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Seamly2D is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Seamly2D.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef VTOOLPOINTFROMARCANDTANGENT_H
#define VTOOLPOINTFROMARCANDTANGENT_H

#include <qcompilerdetection.h>
#include <QDomElement>
#include <QGraphicsItem>
#include <QMetaObject>
#include <QObject>
#include <QPointF>
#include <QString>
#include <QtGlobal>

#include "../ifc/xml/vabstractpattern.h"
#include "../vmisc/def.h"
#include "vtoolsinglepoint.h"

template <class T> class QSharedPointer;

class VToolPointFromArcAndTangent : public VToolSinglePoint
{
    Q_OBJECT
public:
    virtual void setDialog() Q_DECL_OVERRIDE;
    static VToolPointFromArcAndTangent *Create(QSharedPointer<DialogTool> dialog, VMainGraphicsScene  *scene,
                                               VAbstractPattern *doc, VContainer *data);
    static VToolPointFromArcAndTangent *Create(const quint32 _id, const QString &pointName, quint32 arcId,
                                               quint32 tangentPointId, CrossCirclesPoint crossPoint, const qreal &mx,
                                               const qreal &my, VMainGraphicsScene *scene, VAbstractPattern *doc,
                                               VContainer *data, const Document &parse, const Source &typeCreation);
    static QPointF FindPoint(const QPointF &p, const VArc *arc, const CrossCirclesPoint pType);
    static const QString ToolType;
    virtual int  type() const Q_DECL_OVERRIDE {return Type;}
    enum { Type = UserType + static_cast<int>(Tool::PointFromArcAndTangent) };

    QString TangentPointName() const;
    QString ArcName() const;

    quint32 GetTangentPointId() const;
    void    SetTangentPointId(const quint32 &value);

    quint32 GetArcId() const;
    void    SetArcId(const quint32 &value);

    CrossCirclesPoint GetCrossCirclesPoint() const;
    void              SetCrossCirclesPoint(const CrossCirclesPoint &value);

    virtual void ShowVisualization(bool show) Q_DECL_OVERRIDE;
protected:
    virtual void RemoveReferens() Q_DECL_OVERRIDE;
    virtual void contextMenuEvent ( QGraphicsSceneContextMenuEvent * event ) Q_DECL_OVERRIDE;
    virtual void SaveDialog(QDomElement &domElement) Q_DECL_OVERRIDE;
    virtual void SaveOptions(QDomElement &tag, QSharedPointer<VGObject> &obj) Q_DECL_OVERRIDE;
    virtual void ReadToolAttributes(const QDomElement &domElement) Q_DECL_OVERRIDE;
    virtual void SetVisualization() Q_DECL_OVERRIDE;
private:
    Q_DISABLE_COPY(VToolPointFromArcAndTangent)

    quint32 arcId;
    quint32 tangentPointId;
    CrossCirclesPoint crossPoint;

    VToolPointFromArcAndTangent(VAbstractPattern *doc, VContainer *data, const quint32 &id, quint32 arcId,
                                quint32 tangentPointId, CrossCirclesPoint crossPoint, const Source &typeCreation,
                                QGraphicsItem * parent = nullptr);
};

#endif // VTOOLPOINTFROMARCANDTANGENT_H
