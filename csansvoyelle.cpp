/*
 * TP2 Qt - exo 2 IHM sans voyelle (sans designer)
 * auteur : Maxime Russier
 * classe : BTS CIEL 2e annee
 * date : 11/10/2026
 */

#include "csansvoyelle.h"
#include <QSpacerItem>
#include <QRegularExpression>

/* ------------ constructeur ------------ */
CsansVoyelle::CsansVoyelle(QWidget *parent)
    : QWidget(parent)
{
    // -- fenetre --
    setWindowTitle("Sans Voyelle");
    resize(450, 150);

    // -- creation des widgets --
    BoutonConvertir = new QPushButton("Conversion", this);
    BoutonQuitter   = new QPushButton("Quitter", this);
    LineEditSaisie   = new QLineEdit(this);
    LineEditResultat = new QLineEdit(this);
    LabelSaisie   = new QLabel("Saisie", this);
    LabelResultat = new QLabel("Resultat", this);

    LineEditResultat->setReadOnly(true);   // on peut pas ecrire ds le resultat

    // -- style des widgets --
    BoutonConvertir->setStyleSheet("background-color: rgb(221, 255, 249); border: 1px solid cyan; padding: 5px;");
    BoutonQuitter->setStyleSheet("background-color: rgb(30, 10, 70); color: gold; padding: 5px;");
    LineEditResultat->setStyleSheet("background-color: rgb(110, 20, 170); color: white;");
    LabelSaisie->setStyleSheet("font-weight: bold;");
    LabelResultat->setStyleSheet("font-weight: bold;");

    // -- creation des layouts --
    hLayout1 = new QHBoxLayout;
    hLayout2 = new QHBoxLayout;
    hLayout3 = new QHBoxLayout;
    vLayout  = new QVBoxLayout;

    // ligne 1 : saisie
    hLayout1->addWidget(LabelSaisie);
    hLayout1->addWidget(LineEditSaisie);

    // ligne 2 : boutons avec un espace au milieu
    hLayout2->addWidget(BoutonConvertir);
    hLayout2->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    hLayout2->addWidget(BoutonQuitter);

    // ligne 3 : resultat
    hLayout3->addWidget(LabelResultat);
    hLayout3->addWidget(LineEditResultat);

    // on empile les 3 lignes ds le layout vertical
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    vLayout->addLayout(hLayout3);

    setLayout(vLayout);   // on applique le layout a la fenetre

    // -- connexions signaux / slots --
    connect(BoutonConvertir, &QPushButton::clicked, this, &CsansVoyelle::onBoutonConvertirClicked);
    connect(BoutonQuitter, &QPushButton::clicked, this, &QWidget::close);   // close() herite de QWidget
}

/* ------------ destructeur ------------ */
CsansVoyelle::~CsansVoyelle()
{
    // rien a faire, Qt supprime les widgets enfants tout seul
}

/* ------------ slot bouton conversion ------------ */
void CsansVoyelle::onBoutonConvertirClicked()
{
    QString saisie = LineEditSaisie->text();            // on recup la saisie
    QString resultat = SupressionVoyelle(saisie);       // on enleve les voyelles
    LineEditResultat->setText(resultat);                // on affiche
}

/* ------------ suppression des voyelles ------------ */
// methode 1 : on parcourt le txt lettre par lettre
QString CsansVoyelle::SupressionVoyelle(QString texte)
{
    QString voyelles = "aeiouyAEIOUYàâäéèêëîïôöùûüÿ";
    QString resultat = "";

    for (int i = 0; i < texte.length(); i++)
    {
        // si la lettre est pas une voyelle on la garde
        if (!voyelles.contains(texte[i]))
            resultat += texte[i];
    }

    return resultat;

    // methode 2 : avec une regex (enlever le return du dessus pr tester)
    // texte.remove(QRegularExpression("[aeiouyAEIOUYàâäéèêëîïôöùûüÿ]"));
    // return texte;
}
