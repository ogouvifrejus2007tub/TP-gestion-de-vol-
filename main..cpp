
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// ===============================
// CLASSE PASSAGER
// ===============================

class Passager {
private:
    int idPassager;
    string nom;
    string prenom;
    string telephone;
    string email;

public:
    Passager(int id, string n, string p, string t, string e) {
        idPassager = id;
        nom = n;
        prenom = p;
        telephone = t;
        email = e;
    }

    ~Passager() {}

    int getId() {
        return idPassager;
    }

    void afficherInformations() {
        cout << "ID : " << idPassager << endl;
        cout << "Nom : " << nom << endl;
        cout << "Prenom : " << prenom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
    }
};


// ===============================
// CLASSE VOL
// ===============================

class Vol {
private:
    string numeroVol;
    string destination;
    string dateVol;
    string heureVol;
    int capacite;
    int nombrePlacesReservees;
    double prixBillet;

public:
    Vol(string numero, string dest, string date,
        string heure, int cap, double prix) {

        numeroVol = numero;
        destination = dest;
        dateVol = date;
        heureVol = heure;
        capacite = cap;
        nombrePlacesReservees = 0;
        prixBillet = prix;
    }

    ~Vol() {}

    string getNumero() {
        return numeroVol;
    }

    double getPrix() {
        return prixBillet;
    }

    int getCapacite() {
        return capacite;
    }

    int getPlacesReservees() {
        return nombrePlacesReservees;
    }

    void ajouterPlace() {
        nombrePlacesReservees++;
    }

    void afficherVol() {
        cout << "Numero du vol : " << numeroVol << endl;
        cout << "Destination : " << destination << endl;
        cout << "Date : " << dateVol << endl;
        cout << "Heure : " << heureVol << endl;
        cout << "Capacite : " << capacite << endl;
        cout << "Places confirmees : " << nombrePlacesReservees << endl;
        cout << "Prix du billet : " << prixBillet << endl;
    }

    bool verifierDisponibilite() {
        return nombrePlacesReservees < capacite;
    }
};


// ===============================
// CLASSE PAIEMENT
// ===============================

class Paiement {
private:
    int idPaiement;
    double montant;
    string datePaiement;
    string statutPaiement;

public:
    Paiement(int id, double m, string date) {
        idPaiement = id;
        montant = m;
        datePaiement = date;
        statutPaiement = "Valide";
    }

    ~Paiement() {}

    double getMontant() {
        return montant;
    }

    void afficherPaiement() {
        cout << "ID paiement : " << idPaiement << endl;
        cout << "Montant : " << montant << endl;
        cout << "Date : " << datePaiement << endl;
        cout << "Statut : " << statutPaiement << endl;
    }
};


// ===============================
// CLASSE REMBOURSEMENT
// ===============================

class Remboursement {
private:
    int idRemboursement;
    double montant;
    string dateRemboursement;
    string statutRemboursement;

public:
    Remboursement(int id, double m, string date) {
        idRemboursement = id;
        montant = m;
        dateRemboursement = date;
        statutRemboursement = "Effectue";
    }

    ~Remboursement() {}

    void afficherRemboursement() {
        cout << "ID remboursement : " << idRemboursement << endl;
        cout << "Montant rembourse : " << montant << endl;
        cout << "Date : " << dateRemboursement << endl;
        cout << "Statut : " << statutRemboursement << endl;
    }
};


// ===============================
// CLASSE RESERVATION
// ===============================

class Reservation {
private:
    int idReservation;
    string dateReservation;
    string statut;
    int idPassager;
    string numeroVol;
    bool paiementEffectue;
    bool remboursementEffectue;

public:
    Reservation(int id, string date, int passager, string vol) {
        idReservation = id;
        dateReservation = date;
        idPassager = passager;
        numeroVol = vol;
        statut = "En attente";
        paiementEffectue = false;
        remboursementEffectue = false;
    }

    ~Reservation() {}

    int getId() {
        return idReservation;
    }

    int getIdPassager() {
        return idPassager;
    }

    string getNumeroVol() {
        return numeroVol;
    }

    string getStatut() {
        return statut;
    }

    bool aPaye() {
        return paiementEffectue;
    }

    bool aEteRembourse() {
        return remboursementEffectue;
    }

    void confirmerReservation() {
        statut = "Confirmee";
        paiementEffectue = true;
    }

    void annulerReservation() {
        statut = "Annulee";
    }

    void confirmerRemboursement() {
        remboursementEffectue = true;
    }

    void afficherReservation() {
        cout << "ID reservation : " << idReservation << endl;
        cout << "Date : " << dateReservation << endl;
        cout << "ID passager : " << idPassager << endl;
        cout << "Numero du vol : " << numeroVol << endl;
        cout << "Statut : " << statut << endl;
    }
};


// ===============================
// PROGRAMME PRINCIPAL
// ===============================

int main() {

    vector<Passager> passagers;
    vector<Vol> vols;
    vector<Reservation> reservations;
    vector<Paiement> paiements;
    vector<Remboursement> remboursements;

    int choix;
    int prochainIdPassager = 1;
    int prochainIdReservation = 1;
    int prochainIdPaiement = 1;
    int prochainIdRemboursement = 1;

    do {

        cout << "\n====================================" << endl;
        cout << " GESTION DES VOLS ET RESERVATIONS" << endl;
        cout << "====================================" << endl;

        cout << "1. Enregistrer un passager" << endl;
        cout << "2. Ajouter un vol" << endl;
        cout << "3. Afficher les vols disponibles" << endl;
        cout << "4. Rechercher un vol" << endl;
        cout << "5. Effectuer une reservation" << endl;
        cout << "6. Enregistrer un paiement" << endl;
        cout << "7. Annuler une reservation" << endl;
        cout << "8. Consulter les reservations" << endl;
        cout << "9. Afficher les informations d'une reservation" << endl;
        cout << "10. Quitter" << endl;

        cout << "\nVotre choix : ";
        cin >> choix;

        // OPTION 1 : ENREGISTRER UN PASSAGER

        if (choix == 1) {

            string nom, prenom, telephone, email;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Nom : ";
            getline(cin, nom);

            cout << "Prenom : ";
            getline(cin, prenom);

            cout << "Telephone : ";
            getline(cin, telephone);

            cout << "Email : ";
            getline(cin, email);

            passagers.push_back(Passager(
                prochainIdPassager, nom, prenom, telephone, email));

            cout << "Passager enregistre avec succes." << endl;
            cout << "Son identifiant est : " << prochainIdPassager << endl;

            prochainIdPassager++;
        }


        // OPTION 2 : AJOUTER UN VOL

        else if (choix == 2) {

            string numero, destination, date, heure;
            int capacite;
            double prix;

            cout << "Numero du vol : ";
            cin >> numero;

            cout << "Destination : ";
            cin >> destination;

            cout << "Date du vol : ";
            cin >> date;

            cout << "Heure du vol : ";
            cin >> heure;

            cout << "Capacite : ";
            cin >> capacite;

            cout << "Prix du billet : ";
            cin >> prix;

            if (capacite <= 0 || prix <= 0) {
                cout << "Capacite ou prix invalide." << endl;
            }
            else {
                bool existe = false;

                for (int i = 0; i < vols.size(); i++) {
                    if (vols[i].getNumero() == numero) {
                        existe = true;
                    }
                }

                if (existe) {
                    cout << "Ce numero de vol existe deja." << endl;
                }
                else {
                    vols.push_back(Vol(numero, destination, date,
                                       heure, capacite, prix));

                    cout << "Vol ajoute avec succes." << endl;
                }
            }
        }


        // OPTION 3 : AFFICHER LES VOLS DISPONIBLES

        else if (choix == 3) {

            bool trouve = false;

            for (int i = 0; i < vols.size(); i++) {

                if (vols[i].verifierDisponibilite()) {
                    vols[i].afficherVol();
                    cout << "------------------------" << endl;
                    trouve = true;
                }
            }

            if (!trouve) {
                cout << "Aucun vol disponible." << endl;
            }
        }


        // OPTION 4 : RECHERCHER UN VOL

        else if (choix == 4) {

            string numero;
            bool trouve = false;

            cout << "Entrer le numero du vol : ";
            cin >> numero;

            for (int i = 0; i < vols.size(); i++) {

                if (vols[i].getNumero() == numero) {
                    vols[i].afficherVol();
                    trouve = true;
                    break;
                }
            }

            if (!trouve) {
                cout << "Vol introuvable." << endl;
            }
        }


        // OPTION 5 : EFFECTUER UNE RESERVATION

        else if (choix == 5) {

            int idPassager;
            string numeroVol;
            bool passagerExiste = false;
            bool volExiste = false;
            int indiceVol = -1;

            cout << "Identifiant du passager : ";
            cin >> idPassager;

            cout << "Numero du vol : ";
            cin >> numeroVol;

            for (int i = 0; i < passagers.size(); i++) {
                if (passagers[i].getId() == idPassager) {
                    passagerExiste = true;
                }
            }

            for (int i = 0; i < vols.size(); i++) {
                if (vols[i].getNumero() == numeroVol) {
                    volExiste = true;
                    indiceVol = i;
                }
            }

            if (!passagerExiste) {
                cout << "Ce passager n'est pas enregistre." << endl;
            }

            else if (!volExiste) {
                cout << "Ce vol n'existe pas." << endl;
            }

            else {

                bool dejaReserve = false;

                for (int i = 0; i < reservations.size(); i++) {

                    if (reservations[i].getIdPassager() == idPassager &&
                        reservations[i].getNumeroVol() == numeroVol &&
                        reservations[i].getStatut() != "Annulee") {

                        dejaReserve = true;
                    }
                }

                if (dejaReserve) {
                    cout << "Ce passager a deja une reservation sur ce vol." << endl;
                }

                else if (!vols[indiceVol].verifierDisponibilite()) {
                    cout << "Ce vol est complet." << endl;
                }

                else {

                    string date;

                    cout << "Date de la reservation : ";
                    cin >> date;

                    reservations.push_back(
                        Reservation(prochainIdReservation, date,
                                    idPassager, numeroVol));

                    cout << "Reservation enregistree." << endl;
                    cout << "Identifiant : " << prochainIdReservation << endl;
                    cout << "La place sera confirmee apres paiement." << endl;

                    prochainIdReservation++;
                }
            }
        }


        // OPTION 6 : ENREGISTRER UN PAIEMENT

        else if (choix == 6) {

            int idReservation;
            cout << "Identifiant de la reservation : ";
            cin >> idReservation;

            int indiceReservation = -1;
            int indiceVol = -1;

            for (int i = 0; i < reservations.size(); i++) {
                if (reservations[i].getId() == idReservation) {
                    indiceReservation = i;
                }
            }

            if (indiceReservation == -1) {
                cout << "Reservation introuvable." << endl;
            }

            else if (reservations[indiceReservation].getStatut() == "Annulee") {
                cout << "Impossible de payer une reservation annulee." << endl;
            }

            else if (reservations[indiceReservation].aPaye()) {
                cout << "Cette reservation est deja payee." << endl;
            }

            else {

                string numero = reservations[indiceReservation].getNumeroVol();

                for (int i = 0; i < vols.size(); i++) {
                    if (vols[i].getNumero() == numero) {
                        indiceVol = i;
                    }
                }

                if (indiceVol == -1) {
                    cout << "Vol introuvable." << endl;
                }

                else if (!vols[indiceVol].verifierDisponibilite()) {
                    cout << "Aucune place disponible pour confirmer ce paiement." << endl;
                }

                else {

                    double montant;
                    string date;

                    cout << "Montant a payer : ";
                    cin >> montant;

                    cout << "Date du paiement : ";
                    cin >> date;

                    if (montant != vols[indiceVol].getPrix()) {
                        cout << "Montant incorrect. Paiement non valide." << endl;
                    }

                    else {

                        paiements.push_back(
                            Paiement(prochainIdPaiement, montant, date));

                        reservations[indiceReservation].confirmerReservation();
                        vols[indiceVol].ajouterPlace();

                        cout << "Paiement valide." << endl;
                        cout << "Reservation confirmee." << endl;

                        prochainIdPaiement++;
                    }
                }
            }
        }


        // OPTION 7 : ANNULER UNE RESERVATION

        else if (choix == 7) {

            int idReservation;

            cout << "Identifiant de la reservation : ";
            cin >> idReservation;

            int indice = -1;

            for (int i = 0; i < reservations.size(); i++) {
                if (reservations[i].getId() == idReservation) {
                    indice = i;
                }
            }

            if (indice == -1) {
                cout << "Reservation introuvable." << endl;
            }

            else if (reservations[indice].getStatut() == "Annulee") {
                cout << "Cette reservation est deja annulee." << endl;
            }

            else {

                reservations[indice].annulerReservation();

                cout << "Reservation annulee." << endl;

                if (reservations[indice].aPaye()) {

                    if (!reservations[indice].aEteRembourse()) {

                        double montant;
                        string date;

                        cout << "Montant du remboursement selon les regles applicables : ";
                        cin >> montant;

                        if (montant < 0 || montant > 0) {

                            if (montant <= paiements.back().getMontant()) {

                                cout << "Date du remboursement : ";
                                cin >> date;

                                remboursements.push_back(
                                    Remboursement(prochainIdRemboursement,
                                                  montant, date));

                                reservations[indice].confirmerRemboursement();

                                remboursements.back().afficherRemboursement();

                                prochainIdRemboursement++;
                            }
                            else {
                                cout << "Montant superieur au paiement." << endl;
                            }
                        }
                        else {
                            cout << "Aucun remboursement enregistre." << endl;
                        }
                    }
                }
            }
        }


        // OPTION 8 : CONSULTER LES RESERVATIONS

        else if (choix == 8) {

            if (reservations.empty()) {
                cout << "Aucune reservation enregistree." << endl;
            }

            else {
                for (int i = 0; i < reservations.size(); i++) {
                    reservations[i].afficherReservation();
                    cout << "------------------------" << endl;
                }
            }
        }


        // OPTION 9 : AFFICHER LES INFORMATIONS D'UNE RESERVATION

        else if (choix == 9) {

            int idReservation;
            bool trouve = false;

            cout << "Identifiant de la reservation : ";
            cin >> idReservation;

            for (int i = 0; i < reservations.size(); i++) {

                if (reservations[i].getId() == idReservation) {

                    reservations[i].afficherReservation();
                    trouve = true;
                    break;
                }
            }

            if (!trouve) {
                cout << "Reservation introuvable." << endl;
            }
        }


        // OPTION 10 : QUITTER

        else if (choix == 10) {
            cout << "Fin du programme. Au revoir !" << endl;
        }

        else {
            cout << "Choix invalide. Reessayez." << endl;
        }

    } while (choix != 10);

    return 0;
}

