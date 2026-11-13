# TP-gestion-de-vol-

# APPLICATION DE GESTION DES VOLS ET DES RÉSERVATIONS DE BILLETS D'AVION

## 1. Présentation du projet

Une agence de voyage située à Cotonou souhaite informatiser la gestion de ses vols et des réservations de billets d'avion.

L'objectif de ce projet est de concevoir et de développer une application permettant de faciliter la gestion des passagers, des vols, des réservations et des paiements.

L'application sera réalisée en C++ en utilisant les principes de la programmation orientée objet.

## 2. Objectifs du projet

- Enregistrer et gérer les passagers.
- Ajouter et gérer les vols.
- Effectuer et suivre les réservations.
- Gérer les paiements.
- Gérer les annulations et les remboursements.
- Vérifier la disponibilité des places dans les vols.

## 3. Fonctionnalités attendues

L'application doit permettre de :

1. Enregistrer un passager.
2. Ajouter un vol.
3. Afficher les vols disponibles.
4. Rechercher un vol.
5. Effectuer une réservation.
6. Enregistrer un paiement.
7. Annuler une réservation.
8. Consulter les réservations.
9. Afficher les informations d'une réservation.
10. Quitter l'application.

## 4. Règles de gestion

- Un passager doit être enregistré avant de pouvoir réserver un billet.
- Un vol ne peut pas recevoir plus de réservations que sa capacité.
- Un passager ne peut pas réserver deux fois sur le même vol.
- Une réservation doit être associée à un seul passager et à un seul vol.
- Une réservation annulée ne peut plus être utilisée pour effectuer un paiement.
- Une place est considérée comme définitivement réservée uniquement après validation du paiement.
- Une réservation payée et annulée doit être traitée selon les règles de remboursement.

## 5. Modélisation UML

Les classes principales identifiées sont :

- Passager
- Vol
- Reservation
- Paiement
- Remboursement

Le diagramme de classes représente les attributs, les méthodes et les associations entre ces différentes classes.

## 6. Technologies utilisées

- C++ : implémentation de l'application.
- PlantUML : réalisation du diagramme de classes.
- GitHub : stockage et partage du projet.

## 7. Notions de programmation utilisées

- Programmation orientée objet (POO).
- Encapsulation.
- Classes et objets.
- Attributs et méthodes.
- Constructeurs et destructeurs.
- Associations entre objets.
- Collections pour le stockage des données.

## 8. Conclusion

Ce projet permettra de mettre en pratique les notions de programmation orientée objet et de modélisation UML à travers la conception d'une application de gestion des vols et des réservations de billets d'avion.


# MODELISATION UML
## Application de gestion des vols et des réservations de billets d'avion

## 1. Identification des classes

Après l'analyse du problème posé, j'ai identifié cinq classes principales :

- Passager
- Vol
- Reservation
- Paiement
- Remboursement

Ces classes représentent les principales entités nécessaires au fonctionnement de l'application.

## 2. Identification des attributs et des méthodes

### Classe Passager

Attributs :
- idPassager : int
- nom : string
- prenom : string
- telephone : string
- email : string

Méthodes :
- enregistrer()
- afficherInformations()

### Classe Vol

Attributs :
- numeroVol : string
- destination : string
- dateVol : string
- heureVol : string
- capacite : int
- nombrePlacesReservees : int
- prixBillet : double

Méthodes :
- afficherVol()
- verifierDisponibilite()
- rechercherVol()

### Classe Reservation

Attributs :
- idReservation : int
- dateReservation : string
- statut : string

Méthodes :
- effectuerReservation()
- annulerReservation()
- afficherReservation()

### Classe Paiement

Attributs :
- idPaiement : int
- montant : double
- datePaiement : string
- statutPaiement : string

Méthodes :
- enregistrerPaiement()
- verifierPaiement()

### Classe Remboursement

Attributs :
- idRemboursement : int
- montant : double
- dateRemboursement : string
- statutRemboursement : string

Méthodes :
- effectuerRemboursement()
- afficherRemboursement()

## 3. Associations entre les classes

Les associations identifiées sont les suivantes :

- Un passager peut effectuer plusieurs réservations.
- Une réservation appartient à un seul passager.
- Un vol peut recevoir plusieurs réservations.
- Une réservation concerne un seul vol.
- Une réservation peut avoir un paiement.
- Un paiement est associé à une seule réservation.
- Un paiement peut donner lieu à un remboursement.
- Un remboursement concerne un seul paiement.

## 4. Multiplicités des associations

- Passager (1) — Reservation (0..*)
- Vol (1) — Reservation (0..*)
- Reservation (1) — Paiement (0..1)
- Paiement (1) — Remboursement (0..1)

## 5. Conclusion

Cette modélisation permet de représenter les différentes entités de l'application ainsi que leurs relations. Elle servira de base à la réalisation du diagramme de classes UML et à l'implémentation en C++.
