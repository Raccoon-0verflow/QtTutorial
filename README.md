# TP2 Qt - Sans Voyelle 🦝

TP fait en BTS CIEL 2e annee (lycee Branly), sur Qt Creator.

## C'est quoi ?

Une petite appli graphique qui enleve les voyelles d'une phrase.
On tape un texte dans "Saisie", on clique sur **Conversion** et le resultat s'affiche en dessous.
Le bouton **Quitter** ferme l'appli.

L'interface est faite **sans le Designer**, tout est code a la main dans la classe `CsansVoyelle` (qui herite de QWidget).

## Fichiers

- `sansVoyelle.pro` : le fichier projet (qmake)
- `main.cpp` : lance l'appli et affiche la fenetre
- `csansvoyelle.h` : declaration de la classe (widgets, layouts, slot...)
- `csansvoyelle.cpp` : le code de la fenetre + la methode pr supprimer les voyelles

## Lancer le projet

1. Cloner le depot
```
git clone https://github.com/Raccoon-0verflow/QtTutorial.git
```
2. Ouvrir `sansVoyelle.pro` avec Qt Creator
3. Compiler et lancer (fleche verte)

## Test

| Saisie | Resultat attendu |
|---|---|
| bienvenue en BTS SNIR 2ième année | bnvn n BTS SNR 2m nn |

## Ce que j'ai appris

- creer une IHM en code avec des layouts (QHBoxLayout / QVBoxLayout)
- connecter des signaux a des slots avec `connect`
- parcourir un QString caractere par caractere (+ la methode avec une regex)
- utiliser git et github avec Qt Creator

---
Maxime Russier - BTS CIEL
