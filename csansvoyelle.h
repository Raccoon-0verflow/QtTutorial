/*
 * TP2 Qt - exo 2 IHM sans voyelle (sans designer)
 * auteur : Maxime Russier
 * classe : BTS CIEL 2e annee
 * date : 11/10/2026
 */

#ifndef CSANSVOYELLE_H
#define CSANSVOYELLE_H

// -- includes des widgets utilises --
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CsansVoyelle : public QWidget   // herite de QWidget
{
    Q_OBJECT   // obligatoire pr les signaux/slots

public:
    explicit CsansVoyelle(QWidget *parent = nullptr);   // constructeur
    ~CsansVoyelle();                                    // destructeur

    QString SupressionVoyelle(QString texte);   // enleve les voyelles du txt

private slots:
    void onBoutonConvertirClicked();   // appele qd on clique sur conversion

private:
    // -- boutons --
    QPushButton *BoutonConvertir;
    QPushButton *BoutonQuitter;

    // -- zones de saisie --
    QLineEdit *LineEditSaisie;
    QLineEdit *LineEditResultat;

    // -- labels --
    QLabel *LabelSaisie;
    QLabel *LabelResultat;

    // -- layouts --
    QHBoxLayout *hLayout1;   // ligne saisie
    QHBoxLayout *hLayout2;   // ligne boutons
    QHBoxLayout *hLayout3;   // ligne resultat
    QVBoxLayout *vLayout;    // englobe les 3
};

#endif // CSANSVOYELLE_H
