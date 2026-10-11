/*
 * TP2 Qt - exo 2 IHM sans voyelle (sans designer)
 * auteur : Maxime Russier
 * classe : BTS CIEL 2e annee
 * date : 11/10/2026
 */

#include <QApplication>
#include "csansvoyelle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   // appli graphique (pas QCoreApplication)

    CsansVoyelle fenetre;   // on cree la fenetre
    fenetre.show();         // on l'affiche

    return a.exec();   // boucle qui attend les clics etc
}
