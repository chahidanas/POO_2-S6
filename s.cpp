#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Personne { //class abstraite
protected:
	string nom;
	string prenom;
	int age;
public:
	Personne(string n,string p,int a):nom(n),prenom(p),age(a){}
	virtual void afficher() = 0;  //fonction virtual pure = 0 
};

class Etudiant : public Personne {
private:
	string niveau;
public:
	Etudiant(string n, string p, int a,string nv):Personne(n,p,a),niveau(nv){}
	void afficher() override {
		cout << "Nom :" << nom << endl;
		cout << "Prenom : " << prenom << endl;
		cout << "Age : " << age << endl;
		cout << "Niveau Scolaire : " << niveau << endl;
	}
};
class Professeur : public Personne {
private:
	string classe;
public:
	Professeur(string n, string p, int a, string cs):Personne(n, p, a),classe(cs){}
	void afficher() override {
		cout << "Nom :" << nom << endl;
		cout << "Prenom : " << prenom << endl;
		cout << "Age : " << age << endl;
		cout << "Classe : " << classe << endl;
	}
};

class Ecole {
private:
	string nom;
	vector<Etudiant*> elvs;
	vector<Professeur*> profs;
public:
	Ecole(string n):nom(n){}
	
	void ajouterEtud(Etudiant* E) {
		elvs.push_back(E);
		cout << "Taille Tableau Eleves : " << elvs.size() << endl;
	}
	void ajouterProf(Professeur* P) {
		profs.push_back(P);
		cout << "Taille Tableau Profs : " << profs.size() << endl;
	}
	void SupprimerEtud(Etudiant* E) {
		int indexasupprime = -1;
		for (int i = 0; i < elvs.size(); i++) {
			if (elvs[i] == E) {
				indexasupprime = i;
			}
		}
		if (indexasupprime == -1) {
			cout << "Eleve Introuvable" << endl;
		}
		else {
			elvs.erase(elvs.begin() + indexasupprime);
		}
	}
	void SupprimerProf(Professeur* P) {
		int indexasupprime = -1;
		for (int i = 0; i < profs.size(); i++) {
			if (profs[i] == P) {
				indexasupprime = i;
			}
		}
		if (indexasupprime == -1) {
			cout << "Prof Introuvable" << endl;
		}
		else {
			profs.erase(profs.begin() + indexasupprime);
		}
	}
	template<typename T>
	void affichertab(vector<T*> tab) {
		cout << "Liste :" << endl;
		for (auto element : tab) {
			element->afficher();
		}
		cout << "End" << endl;
	}
	vector<Etudiant*>& getEtudiants() { return elvs; }
	vector<Professeur*>& getProfesseurs() { return profs; }
};

int main() {
	Etudiant etud1("Dupont", "Alice", 20, "Licence 1");
	Etudiant etud2("Martin", "Bob", 22, "Master 1");
	Professeur prof1("Durand", "Charles", 45, "Mathematiques");
	Professeur prof2("Leroy", "Diane", 50, "Physique");
	Professeur prof3("z", "z", 50, "z");

	Ecole ecole("Ecole Polytechnique");

	ecole.ajouterEtud(&etud1);
	ecole.ajouterEtud(&etud2);

	ecole.ajouterProf(&prof1);
	ecole.ajouterProf(&prof2);

	cout << "Liste des etudiants :" << endl;
	ecole.affichertab(ecole.getEtudiants());
	cout << endl;

	cout << "Liste des professeurs :" << endl;
	ecole.affichertab(ecole.getProfesseurs());
	cout << endl;
	ecole.SupprimerEtud(&etud1);
	ecole.SupprimerProf(&prof1);
	ecole.SupprimerProf(&prof3);

	cout << "Liste des etudiants apres suppression :" << endl;
	ecole.affichertab(ecole.getEtudiants());
	cout << endl;

	cout << "Liste des professeurs apres suppression :" << endl;
	ecole.affichertab(ecole.getProfesseurs());
	cout << endl;

	return 0;
}
