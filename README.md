<p align="center">
  <img 
    src="https://github.com/JorisLne/42-project-badges/blob/main/covers/cover-so_long.png?raw=true" 
    alt="Bannière solong" 
    width="80%">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Score-100%2F100-brightgreen?style=flat-square" alt="Score du projet 100/100" />
  <img src="https://img.shields.io/badge/Langage-C-blue.svg?style=flat-square&logo=c" alt="Langage C" />
</p>

<p align="center">
  <img src="https://github.com/JorisLne/42-project-badges/blob/main/badges/so_longe.png?raw=true" alt="Badge solong">
</p>



## 🎯 Objectif

Collecter tous les objets (`C`) d'une carte, puis atteindre la sortie (`E`) en incarnant un joueur (`P`). Le tout dans une interface graphique rétro réalisée avec **MiniLibX**.

---

## 🧠 Overview

- Le jeu se lance avec une carte `.ber` (format personnalisé).
- Chaque carte contient :
  - `1` joueur (`P`)
  - `1` sortie (`E`)
  - `≥1` objets à collecter (`C`)
  - Des murs (`1`) et du sol vide (`0`)

- Les conditions de victoire :
  - Ramasser tous les objets `C`
  - Atteindre la sortie `E`

- La carte doit respecter des contraintes :
  - Être rectangulaire
  - Entourée de murs
  - Avoir un seul point de départ et une seule sortie
  - Être entièrement accessible par le joueur

---

## 🛠️ Installation

### 1. Pré-requis

- Système UNIX (Linux ou macOS)
- Bibliothèque graphique miniLibX installée
- `make` et compilateur `gcc`

### 2. Compilation

```bash
git clone https://github.com/votre-repo/solong.git
cd solong
make
```
---

## 📦 Dépendances

- **libft** – fonctions utilitaires (ex. `ft_strlen`, `ft_itoa`, etc.)
- **MiniLibX** – affichage des images, gestion des fenêtres et événements clavier

---

## 🗺️ Format des Cartes

Voici un exemple visuel d'une carte :

```
111111
1P0C01
100001
1C0E11
111111
```

🔹 Légende :
- `1` : Wall 🧱
- `0` : Floor 🌱
- `P` : Player 🧍
- `C` : Collectible 💎
- `E` : Exit 🚪

---

## ✨ Key features

- Mouvement au clavier (WASD)
- Interface graphique en 2D
- Chargement dynamique de cartes
- Affichage en XPM (textures personnalisées)
- Validation complète de la carte (vérifie murs, objets, accessibilité…)

---

## 🧪 Cartes

📁 `maps/valid/` contient :
- `map1.ber`, `map2.ber`, `map3.ber` : cartes jouables.

📁 `maps/invalid/` contient des erreurs fréquentes comme :
- Plusieurs joueurs ou sorties
- Murs incomplets
- Objets manquants
- Extension incorrecte (`.ber` obligatoire)

---
