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
 **  @file   dialognewmeasurements.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   12 7, 2015
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

#ifndef DIALOGNEWMEASUREMENTS_H
#define DIALOGNEWMEASUREMENTS_H

#include <QDialog>

#include "../vmisc/def.h"

namespace Ui
{
    class DialogNewMeasurements;
}

class DialogNewMeasurements : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewMeasurements(QWidget *parent = nullptr);
    ~DialogNewMeasurements();

    MeasurementsType Type() const;
    Unit MUnit() const;
    int BaseSize() const;
    int BaseHeight() const;

protected:
    virtual void changeEvent(QEvent* event) Q_DECL_OVERRIDE;
    virtual void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;

private slots:
    void CurrentTypeChanged(int index);
    void CurrentUnitChanged(int index);

private:
    Q_DISABLE_COPY(DialogNewMeasurements)
    Ui::DialogNewMeasurements *ui;
    bool isInitialized;

    void InitMTypes();
    void InitHeightsList();
    void InitSizesList();
    void InitUnits(const MeasurementsType &type);
};

#endif // DIALOGNEWMEASUREMENTS_H
