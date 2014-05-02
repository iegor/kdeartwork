/****************************************************************************
** Form interface generated from reading ui file './configdialog.ui'
**
** Created: Sun Apr 8 21:58:35 2012
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QSpinBox;
class QCheckBox;
class QComboBox;
class QFrame;
class QButtonGroup;
class QRadioButton;
class QPushButton;
class QTabWidget;
class KColorButton;

class ConfigDialog : public QWidget
{
    Q_OBJECT

public:
    ConfigDialog( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ConfigDialog();

    QGroupBox* generalbox;
    QLabel* textLabel1_3;
    QSpinBox* minTH;
    QCheckBox* ResizeGrip;
    QCheckBox* addAutoSpacing;
    QCheckBox* fullSpec;
    QCheckBox* drawComicFrame;
    QCheckBox* noModalDeco;
    QCheckBox* maxResizable;
    QCheckBox* allowEasyClosing;
    QComboBox* defaultMode;
    QLabel* textLabel1_7;
    QFrame* line3;
    QCheckBox* delAppname;
    QButtonGroup* titlealign;
    QRadioButton* AlignLeft;
    QRadioButton* AlignHCenter;
    QRadioButton* AlignRight;
    QRadioButton* noTitle;
    QPushButton* ButtonColorConfig;
    QTabWidget* tab;
    QWidget* jaguarTab;
    QLabel* textLabel1_4_3;
    QSpinBox* _3DImpact_J;
    QLabel* textLabel2;
    QSpinBox* LineImpact_J;
    QLabel* textLabel1_2_4_3;
    QLabel* textLabel1_8_3;
    QLabel* textLabel1_8_3_2;
    QComboBox* buttonStyle_J;
    QComboBox* titleeffect_J;
    QComboBox* i_titleeffect_J;
    QLabel* textLabel1;
    KColorButton* activeColor1_J;
    KColorButton* activeColor2_J;
    KColorButton* inactiveColor1_J;
    KColorButton* inactiveColor2_J;
    QGroupBox* groupBox2_4;
    QCheckBox* shapeUL_J;
    QCheckBox* shapeLL_J;
    QCheckBox* shapeUR_J;
    QCheckBox* shapeLR_J;
    QSpinBox* borderSize_J;
    QLabel* textLabel1_6_3;
    QCheckBox* drawIcon_J;
    QWidget* pantherTab;
    QLabel* textLabel2_2;
    QSpinBox* LineImpact_P;
    QGroupBox* groupBox2_3;
    QCheckBox* shapeUL_P;
    QCheckBox* shapeLL_P;
    QCheckBox* shapeUR_P;
    QCheckBox* shapeLR_P;
    QSpinBox* borderSize_P;
    QLabel* textLabel1_6_2;
    QLabel* textLabel1_4_4;
    QSpinBox* _3DImpact_P;
    QLabel* textLabel1_2_4;
    QLabel* textLabel1_8;
    QLabel* textLabel1_8_4;
    QComboBox* buttonStyle_P;
    QComboBox* titleeffect_P;
    QComboBox* i_titleeffect_P;
    QLabel* textLabel1_2;
    KColorButton* activeColor1_P;
    KColorButton* activeColor2_P;
    KColorButton* inactiveColor1_P;
    KColorButton* inactiveColor2_P;
    QCheckBox* drawIcon_P;
    QWidget* brushedTab;
    QLabel* textLabel2_3;
    QSpinBox* LineImpact_B;
    QLabel* textLabel1_4;
    QSpinBox* _3DImpact_B;
    QLabel* textLabel1_2_4_2;
    QLabel* textLabel1_8_2;
    QLabel* textLabel1_8_2_2;
    QComboBox* buttonStyle_B;
    QComboBox* titleeffect_B;
    QComboBox* i_titleeffect_B;
    QLabel* textLabel1_5;
    KColorButton* activeColor1_B;
    KColorButton* activeColor2_B;
    KColorButton* inactiveColor1_B;
    KColorButton* inactiveColor2_B;
    QGroupBox* groupBox2_2;
    QCheckBox* shapeUL_B;
    QCheckBox* shapeLL_B;
    QCheckBox* shapeUR_B;
    QCheckBox* shapeLR_B;
    QLabel* textLabel1_6;
    QSpinBox* borderSize_B;
    QCheckBox* drawIcon_B;
    QWidget* TabPage;
    QLabel* textLabel1_4_2;
    QSpinBox* _3DImpact_T;
    QGroupBox* groupBox2_2_2;
    QCheckBox* shapeUL_T;
    QCheckBox* shapeLL_T;
    QCheckBox* shapeUR_T;
    QCheckBox* shapeLR_T;
    QLabel* textLabel1_6_4;
    QSpinBox* borderSize_T;
    QLabel* textLabel1_2_4_2_2;
    QLabel* textLabel1_8_2_3;
    QLabel* textLabel1_8_2_2_2;
    QComboBox* buttonStyle_T;
    QLabel* textLabel1_9;
    QLabel* textLabel1_9_2;
    QLabel* textLabel1_5_2;
    KColorButton* activeColor1_T;
    KColorButton* activeColor2_T;
    QLabel* textLabel1_10;
    QCheckBox* drawIcon_T;
    QWidget* TabPage_2;
    QCheckBox* drawIcon_S;
    QLabel* textLabel1_4_5;
    QSpinBox* _3DImpact_S;
    QLabel* textLabel1_2_4_2_3;
    QLabel* textLabel1_8_2_4;
    QLabel* textLabel1_8_2_2_3;
    QComboBox* buttonStyle_S;
    QComboBox* titleeffect_S;
    QComboBox* i_titleeffect_S;
    QLabel* textLabel1_5_3;
    KColorButton* activeColor1_S;
    KColorButton* activeColor2_S;
    KColorButton* inactiveColor1_S;
    KColorButton* inactiveColor2_S;
    QGroupBox* groupBox2_2_3;
    QCheckBox* shapeUL_S;
    QCheckBox* shapeLL_S;
    QCheckBox* shapeUR_S;
    QCheckBox* shapeLR_S;
    QLabel* textLabel1_6_5;
    QSpinBox* borderSize_S;
    QLabel* textLabel2_3_2;
    QSpinBox* LineImpact_S;

protected:
    QGridLayout* ConfigDialogLayout;
    QSpacerItem* spacer79;
    QSpacerItem* spacer33;
    QGridLayout* generalboxLayout;
    QHBoxLayout* layout133;
    QSpacerItem* spacer6;
    QGridLayout* titlealignLayout;
    QSpacerItem* spacer78;
    QSpacerItem* spacer77;
    QSpacerItem* spacer23_2;
    QGridLayout* jaguarTabLayout;
    QHBoxLayout* layout7_3;
    QSpacerItem* spacer4_3;
    QHBoxLayout* layout10;
    QSpacerItem* spacer5;
    QHBoxLayout* layout40;
    QSpacerItem* spacer18_2_3;
    QVBoxLayout* layout35;
    QVBoxLayout* layout39;
    QVBoxLayout* layout38;
    QHBoxLayout* layout33;
    QHBoxLayout* layout34;
    QGridLayout* groupBox2_4Layout;
    QSpacerItem* spacer24_3;
    QSpacerItem* spacer27_2;
    QSpacerItem* spacer27;
    QSpacerItem* spacer15;
    QVBoxLayout* layout45;
    QSpacerItem* spacer16;
    QVBoxLayout* layout44;
    QSpacerItem* spacer17;
    QGridLayout* pantherTabLayout;
    QHBoxLayout* layout10_2;
    QSpacerItem* spacer5_2;
    QGridLayout* groupBox2_3Layout;
    QSpacerItem* spacer18;
    QSpacerItem* spacer24_2;
    QSpacerItem* spacer28;
    QSpacerItem* spacer28_2;
    QVBoxLayout* layout51;
    QSpacerItem* spacer20;
    QVBoxLayout* layout52;
    QSpacerItem* spacer19;
    QHBoxLayout* layout7_2;
    QSpacerItem* spacer4_4;
    QHBoxLayout* layout50;
    QSpacerItem* spacer18_2;
    QVBoxLayout* layout31;
    QVBoxLayout* layout30;
    QVBoxLayout* layout49;
    QHBoxLayout* layout47;
    QHBoxLayout* layout48;
    QGridLayout* brushedTabLayout;
    QHBoxLayout* layout10_3;
    QSpacerItem* spacer5_3;
    QHBoxLayout* layout7;
    QSpacerItem* spacer4;
    QHBoxLayout* layout57;
    QSpacerItem* spacer18_2_2;
    QVBoxLayout* layout27;
    QVBoxLayout* layout26;
    QVBoxLayout* layout56;
    QHBoxLayout* layout54;
    QHBoxLayout* layout55;
    QGridLayout* groupBox2_2Layout;
    QSpacerItem* spacer23;
    QSpacerItem* spacer24;
    QSpacerItem* spacer29;
    QSpacerItem* spacer29_2;
    QVBoxLayout* layout58;
    QSpacerItem* spacer21;
    QVBoxLayout* layout59;
    QSpacerItem* spacer22;
    QGridLayout* TabPageLayout;
    QHBoxLayout* layout7_4;
    QSpacerItem* spacer4_2;
    QGridLayout* groupBox2_2_2Layout;
    QSpacerItem* spacer23_3;
    QSpacerItem* spacer24_4;
    QSpacerItem* spacer29_3;
    QSpacerItem* spacer29_2_2;
    QVBoxLayout* layout58_2;
    QSpacerItem* spacer21_2;
    QVBoxLayout* layout59_2;
    QSpacerItem* spacer22_2;
    QHBoxLayout* layout42;
    QSpacerItem* spacer18_2_2_2;
    QVBoxLayout* layout27_2;
    QVBoxLayout* layout82;
    QVBoxLayout* layout41;
    QHBoxLayout* layout54_2;
    QGridLayout* TabPageLayout_2;
    QHBoxLayout* layout7_5;
    QSpacerItem* spacer4_5;
    QHBoxLayout* layout57_2;
    QSpacerItem* spacer18_2_2_3;
    QVBoxLayout* layout27_3;
    QVBoxLayout* layout26_2;
    QVBoxLayout* layout56_2;
    QHBoxLayout* layout54_3;
    QHBoxLayout* layout55_2;
    QGridLayout* groupBox2_2_3Layout;
    QSpacerItem* spacer23_4;
    QSpacerItem* spacer24_5;
    QSpacerItem* spacer29_4;
    QSpacerItem* spacer29_2_3;
    QVBoxLayout* layout58_3;
    QSpacerItem* spacer21_3;
    QVBoxLayout* layout59_3;
    QSpacerItem* spacer22_3;
    QHBoxLayout* layout10_3_2;
    QSpacerItem* spacer5_3_2;

protected slots:
    virtual void languageChange();

};

#endif // CONFIGDIALOG_H