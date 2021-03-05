/**
CRINGUREANU IONUT ALEXANDRU
Grupa 1054, Seria D
Proiect POO

Clase:
Tabacherie, Trabuc, Bricheta

Observatii:
[-std=c++11] language standard checked
*/
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <string.h>
#include <conio.h>
#include <fstream>


using namespace std;

/// [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]  T A B A C H E R I E
class Tabacherie {

private:
    string denumire;
	int anDeschidere;
	int nrSucursale;
	string* sucursale;
	int ratings[100];

	const int id;
	static int nrTabacherii;


public:

    /// Constructor default
    Tabacherie() : id(nrTabacherii) {
        this->denumire = "Unknown";
        this->anDeschidere = 0;
        this->nrSucursale = 0;
        this->sucursale = NULL;
        this->nrTabacherii++;

    }

    /// Constructor 1 cu param
    Tabacherie(string denumireP, int anDeschidereP, int nrSucursaleP, string* sucursaleP, int ratingsP[]) : id(nrTabacherii) {
        this->denumire = denumireP;
		this->anDeschidere = anDeschidereP;
		this->nrSucursale = nrSucursaleP;
		this->sucursale = new string[this->nrSucursale];
		for (int i = 0; i < this->nrSucursale; i++) {
			this->sucursale[i] = sucursaleP[i];
			this->ratings[i] = ratingsP[i];
		}

		this->nrTabacherii++;

    }

    /// Constructor 2 cu param
    Tabacherie(int nrSucursaleP, string* sucursaleP, int ratingsP[]) : id(nrTabacherii) {
		this->nrSucursale = nrSucursaleP;
		this->sucursale = new string[this->nrSucursale];
		for (int i = 0; i < this->nrSucursale; i++) {
			this->sucursale[i] = sucursaleP[i];
			this->ratings[i] = ratingsP[i];
		}

		this->nrTabacherii++;

    }

    /// Constructor de copiere
	Tabacherie(const Tabacherie& tabacherie) : id(nrTabacherii) {
		this->denumire = tabacherie.denumire;
		this->anDeschidere = tabacherie.anDeschidere;
		this->nrSucursale = tabacherie.nrSucursale;
		this->sucursale = new string[this->nrSucursale];
		for (int i = 0; i < this->nrSucursale; i++) {
			this->sucursale[i] = tabacherie.sucursale[i];
			this->ratings[i] = tabacherie.ratings[i];
		}

		this->nrTabacherii++;
	}

	/// Supraincarcare operator =
	Tabacherie& operator=(const Tabacherie& tabacherie) {
		this->denumire = tabacherie.denumire;
		this->anDeschidere = tabacherie.anDeschidere;
		this->nrSucursale = tabacherie.nrSucursale;
		this->sucursale = new string[this->nrSucursale];
		for (int i = 0; i < this->nrSucursale; i++) {
			this->sucursale[i] = tabacherie.sucursale[i];
			this->ratings[i] = tabacherie.ratings[i];
		}
		return *this;
	}

	/// Destructor
	~Tabacherie() {
		if (this->sucursale != NULL) {
			delete[] this->sucursale;
		}

		this->nrTabacherii--;
	}

	/// Metoda afisare continut Obiect
	void afisare() {
	    cout << "<> Afisare Tabacherie <><>\n";
		cout << "Denumire: " << this->denumire << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Nr sucursale: " << this->nrSucursale << endl;
		cout << "Sucursale: " << endl;
		for (int i = 0; i < this->nrSucursale; i++) {
			cout << this->sucursale[i] << ", ";
		}
		cout << endl;
		cout << "Ratings: ";
		for (int i = 0; i < this->nrSucursale; i++) {
            cout << this->ratings[i] << " ";
		}
		cout << endl;
		cout << "<> -------------------- <>\n";
	}

	/// GETTERS & SETTERS

	// denumire
	string getDenumire() {
		return this->denumire;
	}

	void setDenumire(string denumire) {
		this->denumire = denumire;
	}

	// anDeschidere
	int getAnDeschidere() {
		return this->anDeschidere;
	}

	void setAnDeschidere(int anDeschidere) {
		this->anDeschidere = anDeschidere;
	}

	// nrSucursale

	int getNrSucursale() {
		return this->nrSucursale;
	}

	// sucursale
	string* getSucursale() {
		return this->sucursale;
	}

	void setSucursale(string* sucursale, int nrSucursale) {
		if (this->sucursale != NULL) {
			delete[] this->sucursale;
		}

		this->nrSucursale = nrSucursale;
		this->sucursale = new string[this->nrSucursale];
		for (int i = 0; i < this->nrSucursale; i++) {
			this->sucursale[i] = sucursale[i];
		}
	}

	// ratings
	int* getRatings() {
        return this->ratings;
	}

	void setRatings(int ratings[]) {
        for(int i = 0; i < this->nrSucursale; i++) {
            this->ratings[i] = ratings[i];
        }
	}

	// getter atribut const id
	int getId() {
		return this->id;
	}

	// getter atribut static nrTabacherii
	static int getNrTabacherii() {
		return nrTabacherii;
	}

	// setter atribut static nrTabacherii
	static void setNrTabacherii(int nrTabacherii) {
		Tabacherie::nrTabacherii = nrTabacherii;
	}

	/// SUPRAINCARCARI OPERATORI

	/// <<
	friend ostream& operator<<(ostream& out, Tabacherie& t) {
		out << "Denumire: " << t.denumire << endl;
		out << "An deschidere: " << t.anDeschidere << endl;
		out << "Nr sucursale: " << t.nrSucursale << endl;
		out << "Sucursale:\n";
		for (int i = 0; i < t.nrSucursale; i++) {
			out << "Sucursala: " << t.sucursale[i] << endl;
		}
		out << "Ratings: ";
		for (int i = 0; i < t.nrSucursale; i++) {
            out << t.ratings[i] << " ";
		}
		out << endl;
		out << "Id: " << t.id << endl;
		out << "Numar tabacherii: " << t.nrTabacherii << endl;
		out << endl;
		return out;

	}

	/// >>
	friend istream& operator>>(istream& in, Tabacherie& t) {
		cout << "Denumire: ";
		in >> t.denumire;
		fflush(stdin);
		cout << "An deschidere: ";
		in >> t.anDeschidere;
		cout << "Nr sucursale: ";
		in >> t.nrSucursale;

		if (t.sucursale != NULL) {
			delete[] t.sucursale;
		}

		t.sucursale = new string[t.nrSucursale];
		for (int i = 0; i < t.nrSucursale; i++) {
			cout << "Sucursala " << i + 1 << ": ";
			in >> t.sucursale[i];
			fflush(stdin);
		}

		for (int i = 0; i < t.nrSucursale; i++) {
            cout << "Rating " << i + 1 << ": ";
            in >> t.ratings[i];
		}

		return in;
	}

	/// indexare []

	string& operator[](int index) {
		if (index < 0 || index > this->nrSucursale) {
			cout << "Index in afara limitelor (out of bounds)";
			throw "Exceptie - Out of Bounds";
		}
		else {
			return this->sucursale[index];
		}
	}


	/// egalitate ==
	bool operator==(Tabacherie t) {
		if (this->denumire == t.denumire && this->anDeschidere == t.anDeschidere && this->nrSucursale == t.nrSucursale)
			return true;
		else
			return false;
	}

	/// >=
	// Supraincarcare operator >= pt verificare vechime tabacherii (anDeschidere1 >= anDeschidere2)
	bool operator>=(Tabacherie t) {
		if (this->anDeschidere >= t.anDeschidere)
			return true;
		else
			return false;
	}

	/// negatie !
	bool operator!() {
		if (this->sucursale != NULL) {
			return false;
		}
		else
			return true;
	}

	/// cast
	explicit operator int() {
		return this->anDeschidere;
	}

	/// operator+
	// t + val
	Tabacherie operator+(int valoare) {
		Tabacherie copie = *this;
		copie.anDeschidere = copie.anDeschidere + valoare;
		return copie;
	}

	// val + t
	friend Tabacherie operator+(int valoare, Tabacherie t) {
		Tabacherie copie = t;
		copie.anDeschidere = copie.anDeschidere + valoare;
		return copie;
	}

	/// operator += pt t +=
	Tabacherie operator+=(int valoare) {
		this->anDeschidere += valoare;
		return *this;
	}

	/// operator ++ prefixat
	Tabacherie& operator++() {
		string * sucursaleNoi = new string[this->nrSucursale + 1];
		for (int i = 0; i < this->nrSucursale; i++) {
			sucursaleNoi[i] = this->sucursale[i];
		}
		sucursaleNoi[this->nrSucursale] = "Sucursala Noua Adaugata";

		/// ratings
		this->ratings[this->nrSucursale] = rand() % 10;

		this->nrSucursale++;
		if (this->sucursale != NULL) {
			delete[] this->sucursale;
		}
		this->sucursale = sucursaleNoi;



		return *this;
	}

	/// operator ++ sufixat
	Tabacherie operator++(int) {
		Tabacherie copie = *this;
		string * sucursaleNoi = new string[this->nrSucursale + 1];
		for (int i = 0; i < this->nrSucursale; i++) {
            sucursaleNoi[i] = this->sucursale[i];
		}
		sucursaleNoi[this->nrSucursale] = "Sucursala Noua Adaugata";

		/// ratings
		this->ratings[this->nrSucursale] = rand() % 10;

		this->nrSucursale++;
		if (this->sucursale != NULL) {
			delete[] this->sucursale;
		}
		this->sucursale = sucursaleNoi;
		return copie;
	}

};

int Tabacherie::nrTabacherii = 0;

/// [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]  T R A B U C
class Trabuc {

private:
    string denumire;
	int anFabricatie;
	int nrModele;
	string* modele;
	int ratings[100];

	const int id;
	static int nrTrabucuri;


public:

    /// Constructor default
    Trabuc() : id(nrTrabucuri) {
        this->denumire = "Unknown";
        this->anFabricatie = 0;
        this->nrModele = 0;
        this->modele = NULL;
        this->nrTrabucuri++;

    }

    /// Constructor 1 cu param
    Trabuc(string denumireP, int anFabricatieP, int nrModeleP, string* modeleP, int ratingsP[]) : id(nrTrabucuri) {
        this->denumire = denumireP;
		this->anFabricatie = anFabricatieP;
		this->nrModele = nrModeleP;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = modeleP[i];
			this->ratings[i] = ratingsP[i];
		}

		this->nrTrabucuri++;

    }

    /// Constructor 2 cu param
    Trabuc(int nrModeleP, string* modeleP, int ratingsP[]) : id(nrTrabucuri) {
		this->nrModele = nrModeleP;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = modeleP[i];
			this->ratings[i] = ratingsP[i];
		}

		this->nrTrabucuri++;

    }

    /// Constructor de copiere
	Trabuc(const Trabuc& trabuc) : id(nrTrabucuri) {
		this->denumire = trabuc.denumire;
		this->anFabricatie = trabuc.anFabricatie;
		this->nrModele = trabuc.nrModele;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = trabuc.modele[i];
			this->ratings[i] = trabuc.ratings[i];
		}

		this->nrTrabucuri++;
	}

	/// Supraincarcare operator =
	Trabuc& operator=(const Trabuc& trabuc) {
		this->denumire = trabuc.denumire;
		this->anFabricatie = trabuc.anFabricatie;
		this->nrModele = trabuc.nrModele;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = trabuc.modele[i];
			this->ratings[i] = trabuc.ratings[i];
		}
		return *this;
	}

	/// Destructor
	~Trabuc() {
		if (this->modele != NULL) {
			delete[] this->modele;
		}

		this->nrTrabucuri--;
	}

	/// Metoda afisare continut Obiect
	void afisare() {
	    cout << "<> Afisare Trabuc <><>\n";
		cout << "Denumire: " << this->denumire << endl;
		cout << "An fabricatie: " << this->anFabricatie << endl;
		cout << "Nr modele: " << this->nrModele << endl;
		cout << "Modele: " << endl;
		for (int i = 0; i < this->nrModele; i++) {
			cout << this->modele[i] << ", ";
		}
		cout << endl;
		cout << "Ratings: ";
		for (int i = 0; i < this->nrModele; i++) {
            cout << this->ratings[i] << " ";
		}
		cout << endl;
		cout << "<> -------------------- <>\n";
	}

	/// GETTERS & SETTERS

	// denumire
	string getDenumire() {
		return this->denumire;
	}

	void setDenumire(string denumire) {
		this->denumire = denumire;
	}

	// anFabricatie
	int getAnFabricatie() {
		return this->anFabricatie;
	}

	void setAnFabricatie(int anFabricatie) {
		this->anFabricatie = anFabricatie;
	}

	// nrModele

	int getNrModele() {
		return this->nrModele;
	}

	// modele
	string* getModele() {
		return this->modele;
	}

	void setModele(string* modele, int nrModele) {
		if (this->modele != NULL) {
			delete[] this->modele;
		}

		this->nrModele = nrModele;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = modele[i];
		}
	}

	// ratings
	int* getRatings() {
        return this->ratings;
	}

	void setRatings(int ratings[]) {
        for(int i = 0; i < this->nrModele; i++) {
            this->ratings[i] = ratings[i];
        }
	}

	// getter atribut const id
	int getId() {
		return this->id;
	}

	// getter atribut static nrTrabucuri
	static int getNrTrabucuri() {
		return nrTrabucuri;
	}

	// setter atribut static nrTrabucuri
	static void setNrTrabucuri(int nrTrabucuri) {
		Trabuc::nrTrabucuri = nrTrabucuri;
	}

	/// SUPRAINCARCARI OPERATORI

	/// <<
	friend ostream& operator<<(ostream& out, Trabuc& t) {
		out << "Denumire: " << t.denumire << endl;
		out << "An fabricatie: " << t.anFabricatie << endl;
		out << "Nr modele: " << t.nrModele << endl;
		out << "Modele:\n";
		for (int i = 0; i < t.nrModele; i++) {
			out << "Model: " << t.modele[i] << endl;
		}
		out << "Ratings: ";
		for (int i = 0; i < t.nrModele; i++) {
            out << t.ratings[i] << " ";
		}
		out << endl;
		out << "Id: " << t.id << endl;
		out << "Numar trabucuri: " << t.nrTrabucuri << endl;
		out << endl;
		return out;

	}

	/// >>
	friend istream& operator>>(istream& in, Trabuc& t) {
		cout << "Denumire: ";
		in >> t.denumire;
		fflush(stdin);
		cout << "An fabricatie: ";
		in >> t.anFabricatie;
		cout << "Nr modele: ";
		in >> t.nrModele;

		if (t.modele != NULL) {
			delete[] t.modele;
		}

		t.modele = new string[t.nrModele];
		for (int i = 0; i < t.nrModele; i++) {
			cout << "Model " << i + 1 << ": ";
			in >> t.modele[i];
			fflush(stdin);
		}

		for (int i = 0; i < t.nrModele; i++) {
            cout << "Rating " << i + 1 << ": ";
            in >> t.ratings[i];
		}

		return in;
	}

	/// indexare []

	string& operator[](int index) {
		if (index < 0 || index > this->nrModele) {
			cout << "Index in afara limitelor (out of bounds)";
			throw "Exceptie - Out of Bounds";
		}
		else {
			return this->modele[index];
		}
	}


	/// egalitate ==
	bool operator==(Trabuc t) {
		if (this->denumire == t.denumire && this->anFabricatie == t.anFabricatie && this->nrModele == t.nrModele)
			return true;
		else
			return false;
	}

	/// >=
	// Supraincarcare operator >= pt verificare vechime trabucuri (anFabricatie1 >= anFabricatie2)
	bool operator>=(Trabuc t) {
		if (this->anFabricatie >= t.anFabricatie)
			return true;
		else
			return false;
	}

	/// negatie !
	bool operator!() {
		if (this->modele != NULL) {
			return false;
		}
		else
			return true;
	}

	/// cast
	explicit operator int() {
		return this->anFabricatie;
	}

	/// operator+
	// t + val
	Trabuc operator+(int valoare) {
		Trabuc copie = *this;
		copie.anFabricatie = copie.anFabricatie + valoare;
		return copie;
	}

	// val + t
	friend Trabuc operator+(int valoare, Trabuc t) {
		Trabuc copie = t;
		copie.anFabricatie = copie.anFabricatie + valoare;
		return copie;
	}

	/// operator += pt t +=
	Trabuc operator+=(int valoare) {
		this->anFabricatie += valoare;
		return *this;
	}

	/// operator ++ prefixat
	Trabuc& operator++() {
		string * modeleNoi = new string[this->nrModele + 1];
		for (int i = 0; i < this->nrModele; i++) {
			modeleNoi[i] = this->modele[i];
		}
		modeleNoi[this->nrModele] = "Model Nou Adaugat";

		/// ratings
		this->ratings[this->nrModele] = rand() % 10;

		this->nrModele++;
		if (this->modele != NULL) {
			delete[] this->modele;
		}
		this->modele = modeleNoi;



		return *this;
	}

	/// operator ++ sufixat
	Trabuc operator++(int) {
		Trabuc copie = *this;
		string * modeleNoi = new string[this->nrModele + 1];
		for (int i = 0; i < this->nrModele; i++) {
            modeleNoi[i] = this->modele[i];
		}
		modeleNoi[this->nrModele] = "Model Nou Adaugat";

		/// ratings
		this->ratings[this->nrModele] = rand() % 10;

		this->nrModele++;
		if (this->modele != NULL) {
			delete[] this->modele;
		}
		this->modele = modeleNoi;
		return copie;
	}

};

int Trabuc::nrTrabucuri = 0;

/// [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]  B R I C H E T A
class Bricheta {

private:
    string denumire;
	int anFabricatie;
	int nrModele;
	string* modele;
	int ratings[100];

	const int id;
	static int nrBrichete;


public:

    /// Constructor default
    Bricheta() : id(nrBrichete) {
        this->denumire = "Unknown";
        this->anFabricatie = 0;
        this->nrModele = 0;
        this->modele = NULL;
        this->nrBrichete++;

    }

    /// Constructor 1 cu param
    Bricheta(string denumireP, int anFabricatieP, int nrModeleP, string* modeleP, int ratingsP[]) : id(nrBrichete) {
        this->denumire = denumireP;
		this->anFabricatie = anFabricatieP;
		this->nrModele = nrModeleP;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = modeleP[i];
			this->ratings[i] = ratingsP[i];
		}

		this->nrBrichete++;

    }

    /// Constructor 2 cu param
    Bricheta(int nrModeleP, string* modeleP, int ratingsP[]) : id(nrBrichete) {
		this->nrModele = nrModeleP;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = modeleP[i];
			this->ratings[i] = ratingsP[i];
		}

		this->nrBrichete++;

    }

    /// Constructor de copiere
	Bricheta(const Bricheta& bricheta) : id(nrBrichete) {
		this->denumire = bricheta.denumire;
		this->anFabricatie = bricheta.anFabricatie;
		this->nrModele = bricheta.nrModele;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = bricheta.modele[i];
			this->ratings[i] = bricheta.ratings[i];
		}

		this->nrBrichete++;
	}

	/// Supraincarcare operator =
	Bricheta& operator=(const Bricheta& bricheta) {
		this->denumire = bricheta.denumire;
		this->anFabricatie = bricheta.anFabricatie;
		this->nrModele = bricheta.nrModele;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = bricheta.modele[i];
			this->ratings[i] = bricheta.ratings[i];
		}
		return *this;
	}

	/// Destructor
	~Bricheta() {
		if (this->modele != NULL) {
			delete[] this->modele;
		}

		this->nrBrichete--;
	}

	/// Metoda afisare continut Obiect
	void afisare() {
	    cout << "<> Afisare Bricheta <><>\n";
		cout << "Denumire: " << this->denumire << endl;
		cout << "An fabricatie: " << this->anFabricatie << endl;
		cout << "Nr modele: " << this->nrModele << endl;
		cout << "Modele: " << endl;
		for (int i = 0; i < this->nrModele; i++) {
			cout << this->modele[i] << ", ";
		}
		cout << endl;
		cout << "Ratings: ";
		for (int i = 0; i < this->nrModele; i++) {
            cout << this->ratings[i] << " ";
		}
		cout << endl;
		cout << "<> -------------------- <>\n";
	}

	/// GETTERS & SETTERS

	// denumire
	string getDenumire() {
		return this->denumire;
	}

	void setDenumire(string denumire) {
		this->denumire = denumire;
	}

	// anFabricatie
	int getAnFabricatie() {
		return this->anFabricatie;
	}

	void setAnFabricatie(int anFabricatie) {
		this->anFabricatie = anFabricatie;
	}

	// nrModele

	int getNrModele() {
		return this->nrModele;
	}

	// modele
	string* getModele() {
		return this->modele;
	}

	void setModele(string* modele, int nrModele) {
		if (this->modele != NULL) {
			delete[] this->modele;
		}

		this->nrModele = nrModele;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = modele[i];
		}
	}

	// ratings
	int* getRatings() {
        return this->ratings;
	}

	void setRatings(int ratings[]) {
        for(int i = 0; i < this->nrModele; i++) {
            this->ratings[i] = ratings[i];
        }
	}

	// getter atribut const id
	int getId() {
		return this->id;
	}

	// getter atribut static nrBrichete
	static int getNrBrichete() {
		return nrBrichete;
	}

	// setter atribut static nrBrichete
	static void setnrBrichete(int nrBrichete) {
		Bricheta::nrBrichete = nrBrichete;
	}

	/// SUPRAINCARCARI OPERATORI

	/// <<
	friend ostream& operator<<(ostream& out, Bricheta& t) {
		out << "Denumire: " << t.denumire << endl;
		out << "An fabricatie: " << t.anFabricatie << endl;
		out << "Nr modele: " << t.nrModele << endl;
		out << "Modele:\n";
		for (int i = 0; i < t.nrModele; i++) {
			out << "Model: " << t.modele[i] << endl;
		}
		out << "Ratings: ";
		for (int i = 0; i < t.nrModele; i++) {
            out << t.ratings[i] << " ";
		}
		out << endl;
		out << "Id: " << t.id << endl;
		out << "Numar brichete: " << t.nrBrichete << endl;
		out << endl;
		return out;

	}

	/// >>
	friend istream& operator>>(istream& in, Bricheta& t) {
		cout << "Denumire: ";
		in >> t.denumire;
		fflush(stdin);
		cout << "An fabricatie: ";
		in >> t.anFabricatie;
		cout << "Nr modele: ";
		in >> t.nrModele;

		if (t.modele != NULL) {
			delete[] t.modele;
		}

		t.modele = new string[t.nrModele];
		for (int i = 0; i < t.nrModele; i++) {
			cout << "Model " << i + 1 << ": ";
			in >> t.modele[i];
			fflush(stdin);
		}

		for (int i = 0; i < t.nrModele; i++) {
            cout << "Rating " << i + 1 << ": ";
            in >> t.ratings[i];
		}

		return in;
	}

	/// indexare []

	string& operator[](int index) {
		if (index < 0 || index > this->nrModele) {
			cout << "Index in afara limitelor (out of bounds)";
			throw "Exceptie - Out of Bounds";
		}
		else {
			return this->modele[index];
		}
	}


	/// egalitate ==
	bool operator==(Bricheta t) {
		if (this->denumire == t.denumire && this->anFabricatie == t.anFabricatie && this->nrModele == t.nrModele)
			return true;
		else
			return false;
	}

	/// >=
	// Supraincarcare operator >= pt verificare vechime brichete (anFabricatie1 >= anFabricatie2)
	bool operator>=(Bricheta t) {
		if (this->anFabricatie >= t.anFabricatie)
			return true;
		else
			return false;
	}

	/// negatie !
	bool operator!() {
		if (this->modele != NULL) {
			return false;
		}
		else
			return true;
	}

	/// cast
	explicit operator int() {
		return this->anFabricatie;
	}

	/// operator+
	// t + val
	Bricheta operator+(int valoare) {
		Bricheta copie = *this;
		copie.anFabricatie = copie.anFabricatie + valoare;
		return copie;
	}

	// val + t
	friend Bricheta operator+(int valoare, Bricheta t) {
		Bricheta copie = t;
		copie.anFabricatie = copie.anFabricatie + valoare;
		return copie;
	}

	/// operator += pt t +=
	Bricheta operator+=(int valoare) {
		this->anFabricatie += valoare;
		return *this;
	}

	/// operator ++ prefixat
	Bricheta& operator++() {
		string * modeleNoi = new string[this->nrModele + 1];
		for (int i = 0; i < this->nrModele; i++) {
			modeleNoi[i] = this->modele[i];
		}
		modeleNoi[this->nrModele] = "Model Nou Adaugat";

		/// ratings
		this->ratings[this->nrModele] = rand() % 10;

		this->nrModele++;
		if (this->modele != NULL) {
			delete[] this->modele;
		}
		this->modele = modeleNoi;



		return *this;
	}

	/// operator ++ sufixat
	Bricheta operator++(int) {
		Bricheta copie = *this;
		string * modeleNoi = new string[this->nrModele + 1];
		for (int i = 0; i < this->nrModele; i++) {
            modeleNoi[i] = this->modele[i];
		}
		modeleNoi[this->nrModele] = "Model Nou Adaugat";

		/// ratings
		this->ratings[this->nrModele] = rand() % 10;

		this->nrModele++;
		if (this->modele != NULL) {
			delete[] this->modele;
		}
		this->modele = modeleNoi;
		return copie;
	}

};

int Bricheta::nrBrichete = 0;

/// [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][] FAZA 2

/// [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][] RaftTabacherie
class RaftTabacherie : public Tabacherie {
protected:
	int nrRaft;
	string numeSucursala;

public:

	RaftTabacherie():Tabacherie() {
	this->nrRaft = 8;
	this->numeSucursala = "SucursalaPtRaft";
	}

	RaftTabacherie(string denumireP, int anDeschidereP, int nrSucursaleP, string* sucursaleP, int ratingsP[], int nrRaftP, string numeSucursalaP) :Tabacherie(denumireP, anDeschidereP, nrSucursaleP, sucursaleP, ratingsP) {
		this->nrRaft = nrRaftP;
		this->numeSucursala = numeSucursalaP;
	}

	RaftTabacherie(const RaftTabacherie &p):Tabacherie(p) {
		this->nrRaft = p.nrRaft;
		this->numeSucursala = p.numeSucursala;
	}

	string getNumeSucursala() {
		return this->numeSucursala;
	}

	void setNumeSucursala(string numeSucursalaN) {
		this->numeSucursala = numeSucursalaN;
	}

	int getNrRaft() {
		return this->nrRaft;
	}

	void setNrRaft(int nrRaftN) {
		this->nrRaft = nrRaftN;
	}

	~RaftTabacherie() {
		// destructor RaftTabacherie
	}

	void afisareRaftTabacherie() {
	    cout << "<> Afisare Raft <><>\n";
		cout << "Denumire: " << this-> getDenumire() << endl;
		cout << "An deschidere: " << this->getAnDeschidere() << endl;
		cout << "Nr raft: " << this->nrRaft << endl;
		cout << "Nume sucursala: " << this->numeSucursala << endl;
		cout << "<> -------------------- <>\n";
	}


};

/// [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][] TrabucAromat
class TrabucAromat : public Trabuc {
protected:
	int intensitate;
	string aroma;
	char* model;

public:

	TrabucAromat():Trabuc() {
	this->intensitate = 5;
	this->aroma = "Struguri";
	this->model = "M420";
	}

	TrabucAromat(string denumireP, int anFabricatieP, int nrModeleP, string* modeleP, int ratingsP[], int intensitateP, string aromaP, char* modelP):Trabuc(denumireP, anFabricatieP, nrModeleP, modeleP, ratingsP) {
		this->intensitate = intensitateP;
		this->aroma = aromaP;
		this->model = modelP;
	}

	TrabucAromat(const TrabucAromat &p):Trabuc(p) {
		this->intensitate = p.intensitate;
		this->aroma = p.aroma;
		this->model = p.model;
	}

	string getAroma() {
		return this->aroma;
	}

	void setAroma(string aromaN) {
		this->aroma = aromaN;
	}

	int getIntensitate() {
		return this->intensitate;
	}

	void setIntensitate(int intensitateN) {
		this->intensitate = intensitateN;
	}

	char* getModel() {
        return this->model;
	}

	void setModel(char* modelN) {
        this->model = modelN;
	}

	~TrabucAromat() {
		// destructor TrabucAromat
	}

	void afisareTrabucAromat() {
	    cout << "<> Afisare TrabucAromat <><>\n";
		cout << "Denumire: " << this->getDenumire() << endl;
		cout << "An fabricatie: " << this->getAnFabricatie() << endl;
		cout << "Intensitate: " << this->intensitate << endl;
		cout << "Aroma: " << this->aroma << endl;
		cout << "Model: " << this->model << endl;
		cout << "<> -------------------- <>\n";
	}


};

/// CLASA ABSTRACTA
class Angajat {
protected:
	string nume;
	int varsta;
	float salariu;

public:
	Angajat() {
		this->nume = "N_default P_default";
		this->varsta = 25;
		this->salariu = 3300;
	}

	Angajat(string numeP, int varstaP, float salariuP) {
		this->nume = numeP;
		this->varsta = varstaP;
		this->salariu = salariuP;
	}

	virtual void afisare() {
		cout << "Nume angajat: " << this->nume << endl;
		cout << "Varsta: " << this->varsta << endl;
		cout << "Salariu: " << this->salariu << endl;
	}

	virtual void getInfoAng() = 0;

	string getNume() {
        return this->nume;
	}

	/// suprascriere operatori pt FAZA 3
	friend ostream& operator<<(ostream& out, Angajat& a) {
		out << "Nume angajat: " << a.nume << endl;
		return out;
	}

	/// setteri
	void setNume(string nume) {
        this->nume = nume;
	}

	void setVarsta(int varsta) {
        this->varsta = varsta;
	}

	void setSalariu(float salariu) {
        this->salariu = salariu;
	}
};

/// INTERFATA
class ISalariu {
	virtual void calculSalariu() = 0;
	virtual float getSalariu() = 0;
};

/// CLASA MOSTENITOARE
class Casier:public Angajat, public ISalariu {
private:
	int vechime;
	float comision;
	string sucursala;

public:
	Casier():Angajat() {
		this->vechime = 3;
		this->comision = 0;
		this->sucursala = "Sucursala Default";
	}

	Casier(string numeP, int varstaP, float salariuP, int vechimeP, float comisionP, string sucursalaP):Angajat(numeP, varstaP, salariuP) {
		this->vechime = vechimeP;
		this->comision = comisionP;
		this->sucursala = sucursalaP;
	}

	void afisare() override {
		cout << "Nume angajat: " << this->nume << endl;
		cout << "Varsta: " << this->varsta << endl;
		cout << "Salariu: " << this->salariu << endl;
		cout << "Vechime: " << this->vechime << endl;
		cout << "Comision: " << this->comision << endl;
		cout << "Sucursala: " << this->sucursala << endl;
	}

	/// setteri
	void setVechime(int vechime) {
        this->vechime = vechime;
	}

	void setComision(float comision) {
        this->comision = comision;
	}

	void setSucursala(string sucursala) {
        this->sucursala = sucursala;
	}

	void afisare(string mesaj) {
		cout << mesaj << endl;
	}

	void getInfoAng() {
		this->afisare();
	}

	void calculSalariu() {
		this->salariu = (1 + (float)this->comision / 100) * this->salariu;
	}

	float getSalariu() {
		return this->salariu;
	}

	/// pt FAZA 3
	friend ostream& operator<< (ostream& out, Casier c) {
		out << "Nume: " << c.nume << endl;
		out << "Varsta: " << c.varsta << endl;
		out << "Salariu: " << c.salariu << endl;
		out << "Vechime: " << c.vechime << endl;
		out << "Comision: " << c.comision << endl;
		out << "Sucursala: " << c.sucursala << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Casier& c) {
		cout << "Nume: ";
		in >> c.nume;
		cout << "Varsta: ";
		in >> c.varsta;
		cout << "Salariu: ";
		in >> c.salariu;
		cout << "Vechime: ";
		in >> c.vechime;
		cout << "Comision: ";
		in >> c.comision;
		cout << "Sucursala: ";
		in >> c.sucursala;
		return in;
	}

	friend ofstream& operator<< (ofstream& out, Casier c) {
		out << c.nume << endl;
		out << c.varsta << endl;
		out << c.salariu << endl;
		out << c.vechime << endl;
		out << c.comision << endl;
		out << c.sucursala << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Casier& c) {
		getline(in, c.nume);
		in >> c.varsta;
		in >> c.salariu;
		in >> c.vechime;
		in >> c.comision;
		getline(in, c.sucursala);
		return in;
	}

};

/// Compunerea claselor - HAS A
class Personal {
private:
    int dimPersonal;
    Angajat** angajati;

public:
    ///
    Personal() {
		this->dimPersonal = 0;
		this->angajati = NULL;
	}

	Personal(int dimPersonal, Angajat** angajati) {
		this->dimPersonal = dimPersonal;
		this->angajati = new Angajat*[this->dimPersonal];
		for(int i = 0; i < this->dimPersonal; i++) {
			this->angajati[i] = angajati[i];
		}
	}

	~Personal() {
		if (this->angajati != NULL) {
			delete[] this->angajati;
		}
	}

	void afisare() {
		cout << "\n<> Afisare personal <>\n";
		cout << "Dimensiune personal: " << this->dimPersonal << "\n\n";
		for (int i = 0; i < this->dimPersonal; i++) {
            cout << "Angajat [" << i+1 << "]" << endl;
			this->angajati[i]->afisare();
			cout << endl;
		}
	}

};

/// [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][] MAIN
int main()
{
    std::srand(std::time(nullptr));
    string denumire = "Tabacheriada";
	int anDeschidere = 1997;
	int nrSucursale = 3;
	string* sucursale = new string[nrSucursale];
	int ratings[nrSucursale];
	for (int i = 0; i < nrSucursale; i++) {
		sucursale[i] = "Sucursala " + to_string(i+1);
		ratings[i] = rand() % 10;
	}

	cout << "\n[-1-] Afisare tabacherie cu constructor 1 (tab_1) [][]\n";
	Tabacherie* tab_1 = new Tabacherie(denumire, anDeschidere, nrSucursale, sucursale, ratings);
	tab_1->afisare();

	cout << "\n[-2-] Afisare tabacherie cu constructor 2 (tab_2) [][]\n";
	Tabacherie* tab_2 = new Tabacherie(nrSucursale, sucursale, ratings);
	tab_2->afisare();

	cout << "\n[-3-] Afisare tabacherie cu constructor default (tab_3) [][]\n";
	Tabacherie* tab_3 = new Tabacherie();
	tab_3->afisare();

	cout << "\n[-4-] Afisare tabacherie cu constructor 1 (tab_4) [][]\n";
	Tabacherie* tab_4 = new Tabacherie("Tabacheria 4", 1969, 3, sucursale, ratings);
	tab_4->afisare();

	/// apel getters & setters - pe Tabacherie tab_4
	cout << "\n[-5-] APEL GETTERS & SETTERS [][]\n";

	cout << "Denumire tab_4: " << tab_4->getDenumire();
	tab_4->setDenumire("Tabacheria 420");
	cout << " | Dupa setter: " << tab_4->getDenumire() << endl;

	cout << "An deschidere: " << tab_4->getAnDeschidere();
	tab_4->setAnDeschidere(1991);
	cout << " | Dupa setter: " << tab_4->getAnDeschidere() << endl;

	cout << "Sucursale: ";
	for(int i = 0; i < tab_4->getNrSucursale(); i++) {
        cout << tab_4->getSucursale()[i] << ", ";
	}
	cout << endl;
	cout << "Ratings: ";
	for(int i = 0; i < tab_4->getNrSucursale(); i ++) {
        cout << tab_4->getRatings()[i] << " ";
	}
	cout << endl;

    string* sucursaleNoi = new string[2];
    sucursaleNoi[0] = "Sucursala I";
    sucursaleNoi[1] = "Sucursala II";
    tab_4->setSucursale(sucursaleNoi, 2);
    int ratingsNoi[2] = {rand() % 10, rand() % 10};
    tab_4->setRatings(ratingsNoi);

    delete sucursaleNoi;

    cout << "Dupa setter: \n";
    for(int i = 0; i < tab_4->getNrSucursale(); i++) {
        cout << tab_4->getSucursale()[i] << ", ";
	}
	cout << endl;

	for(int i = 0; i < tab_4->getNrSucursale(); i++) {
        cout << tab_4->getRatings()[i] << " ";
	}
	cout << endl;

	cout << "ID tab_4: " << tab_4->getId() << endl;
	cout << "nrTabacherii: " << Tabacherie::getNrTabacherii() << endl;

	/// constructor de copiere
	cout << "\n[-6-] Constructor de copiere pe tab_5(tab_4) [][]\n";
	Tabacherie tab_5(*tab_4);
	tab_5.afisare();

	/// supraincarcare operator =
	cout << "\n[-7-] Operator = pe tab_6 = tab_4 [][]\n";
	Tabacherie tab_6 = *tab_4;
	tab_6.afisare();

	/// operator >>
	cout << "\n[-8-] Operator >> pe tab_7 [][]\n";
	Tabacherie tab_7;
	cin >> tab_7;

	/// operator <<
	cout << "\n[-9-] Operator << pe tab_7 [][]\n";
	cout << tab_7;

	/// operator indexare // try catch
	cout << "\n[-10-] Verificam pozitia (5) unei sucursale [][]\n";
	try {
		cout << tab_7[5];
	}
	catch (exception* e) {
		cout << e->what() << endl;
		cout << "\nExceptie prinsa 1" << endl;
	}
	catch (...) {
		cout << "\nExceptie prinsa 2" << endl;
	}

	/// operator ==
	cout << "\n[-11-] Verificare daca (tab_5 == tab_6) [][]\n";
	if(tab_5 == tab_6) {
        cout << "tab_5 == tab_6" << endl;
	} else {
        cout << "tab_5 != tab_6" << endl;
	}

	/// operator >=
	cout << "\n[-12-] Verificare daca (tab_5 >= tab_6) [][]\n";
	if(tab_5 >= tab_6) {
        cout << "tab_5 este cel putin la fel de noua ca tab_6" << endl;
	} else {
        cout << "tab_5 este mai veche decat tab_6" << endl;
	}

	/// operator negatie !
	cout << "\n[-13-] Verificare daca tab_7 continte sucursale [][]\n";
	if(!tab_7) {
        cout << "tab_7 nu contine sucursale\n";
	} else {
        cout << "tab_7 contine sucursale\n";
	}

	/// operator cast int()
	cout << "\n[-14-] Afisare an deschidere tab_6 - op cast int() [][]\n";
	cout << (int)tab_6 << endl;

	/// operator +
	cout << "\n[-15-] Afisare an deschidere tab_6 dupa operatorul +[][]\n";
	tab_6 = tab_6 + 10;
	cout << tab_6.getAnDeschidere() << endl;
	tab_6 = 2 + tab_6;
	cout << tab_6.getAnDeschidere() << endl;

	/// operator +=
	cout << "\n[-16-] Afisare an deschidere tab_6 dupa operatorul +=[][]\n";
	tab_6 += 5;
	cout << tab_6.getAnDeschidere() << endl;

	/// ++ prefixat & sufixat
	cout << "\n[-17-] Adaugare sucursala noua cu operatorul ++[][]\n";
	++tab_7;
	cout << tab_7;
	cout << endl;
	tab_7++;
	cout << tab_7;



	/// [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][] FAZA 2
	cout << "\n[-18-] RaftTabacherie IS A Tabacherie\n";
	RaftTabacherie raft;
	raft.afisareRaftTabacherie();

	cout << "\n[-19-] TrabucAromat IS A Trabuc\n";
	TrabucAromat trab_aromat;
	trab_aromat.afisareTrabucAromat();

	/// clasa abstracta, interfata, clasa mostenitoare
	Casier cas1;
	Casier cas2("Doby Elf", 60, 1000, 10, 15, "Malfoy Residence");

	cout << "\n[-20-] Afisare casier 1 cu constructorul default (cas1)\n";
	cas1.afisare();

	cout << "\n[-21-] Afisare cu metoda afisare() a clasei mostenitoare\n";
	cas1.afisare("mesaj - aceasta nu este metoda suprascrisa");

	cout << "\n[-22-] Afisare casier 2 - functia virtuala pura (getInfoAng)\n";
	cas2.getInfoAng();

	cout << "\n[-23-] Afisare salariul pt casier 2 dupa calculul cu comisionul\n";
	cout << "Salariul cas2 inainte de aplicarea comisionului: " << cas2.getSalariu() << endl;
	cas2.calculSalariu();
	cout << "Salariul cas2 dupa aplicarea comisionului: " << cas2.getSalariu() << endl;

	/// (string numeP, int varstaP, float salariuP, int vechimeP, float comisionP, string sucursalaP)


	/// Compunerea claselor - HAS A
	cout << "\n[-24-] Personal HAS A Angajat || Afisare personal\n";
	Angajat* angajati[2] = {&cas1, &cas2};
	Personal pers(2, angajati);
	pers.afisare();

	/// [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][] FAZA 3

	Casier cas3("Geralt", 80, 6000, 50, 60, "Rivia");
	Casier cas4("Ezio Auditore", 35, 2000, 15, 30, "Firenze");
	Casier cas5("Corvo Attano", 40, 3500, 9, 10, "Dunwall");
	Casier cas6("Geralt", 81, 5999, 51, 59, "Vizima");

	/// STL

	///STL - vector
	cout << "\n[-25-] Afisare vector cu numele angajatilor (STL)\n";
	vector<string> vectorAngajati;
	vectorAngajati.push_back(cas1.getNume());
	vectorAngajati.push_back(cas2.getNume());
	vectorAngajati.push_back(cas3.getNume());
	vectorAngajati.push_back(cas4.getNume());
	vectorAngajati.push_back(cas5.getNume());
	vectorAngajati.push_back(cas6.getNume());
	cout << "Afisare angajati: " << endl;
	for (int i = 0; i < vectorAngajati.size(); i++) {
		cout << vectorAngajati[i] << endl;
	}
	cout << "\nSortare vector:\n";
	sort(vectorAngajati.begin(), vectorAngajati.end());
	vector<string>::iterator it;
	for (it = vectorAngajati.begin(); it != vectorAngajati.end(); it++) {
		cout << *it << endl;
	}

	///STL - set
	cout << "\n[-26-] Afisare set cu numele angajatilor (STL)\n";
	set<string> setAngajati;
	setAngajati.insert(cas1.getNume());
	setAngajati.insert(cas2.getNume());
	setAngajati.insert(cas3.getNume());
	setAngajati.insert(cas4.getNume());
	setAngajati.insert(cas5.getNume());
	setAngajati.insert(cas6.getNume());
	cout << "Afisare angajati din set: " << endl;
	set<string>::iterator it2;
	for (it2 = setAngajati.begin(); it2 != setAngajati.end(); it2++) {
		cout << *it2 << endl;
	}
	cout << "\nSe cauta angajatul cu numele \"Geralt\"...\n";
	it2 = setAngajati.find("Geralt");
	if(it2 != setAngajati.end()) {
		cout << "Angajatul a fost gasit.\n";
	}
	else {
		cout << "Angajatul nu a fost gasit.\n";
	}

	///STL - list
	cout << "\n[-27-] Afisare lista cu numele angajatilor (STL)\n";
	list<string> listaAngajati;
	listaAngajati.push_back(cas1.getNume());
	listaAngajati.push_front(cas2.getNume());
	listaAngajati.push_back(cas3.getNume());
	listaAngajati.push_front(cas4.getNume());
	listaAngajati.push_back(cas5.getNume());
	listaAngajati.push_front(cas6.getNume());

	cout << endl << "Afisare lista angajati:" << endl;
	list<string>::iterator it3;
	for (it3 = listaAngajati.begin(); it3 != listaAngajati.end(); it3++) {
		cout << *it3 << endl;
	}
	cout << "\nAfisare lista angajati dupa apel pop_front: "<<endl;
	listaAngajati.pop_front();
	for (it3 = listaAngajati.begin(); it3 != listaAngajati.end(); it3++) {
		cout << *it3 << endl;
	}

	cout << "\nAfisare lista angajati sortata: \n";
	listaAngajati.sort();
	for (it3 = listaAngajati.begin(); it3 != listaAngajati.end(); it3++) {
		cout << *it3 << endl;
	}

	cout << "\nAfisare lista angajati reversed: \n";
	listaAngajati.reverse();
	for (it3 = listaAngajati.begin(); it3 != listaAngajati.end(); it3++) {
		cout << *it3 << endl;
	}

	///STL - map
	cout << "\n[-28-] Afisare map cu numele angajatilor (STL)\n";
	map<int, Casier> mapAngajati;
	mapAngajati.insert(make_pair(1, cas1));
	mapAngajati.insert(make_pair(2, cas2));
	mapAngajati.insert(make_pair(3, cas3));
	mapAngajati.insert(make_pair(4, cas4));
	mapAngajati.insert(make_pair(5, cas5));
	mapAngajati.insert(make_pair(6, cas6));

	map<int, Casier>::iterator itMap;
	for(itMap = mapAngajati.begin(); itMap != mapAngajati.end(); itMap++) {
		cout << "Cheie: " << itMap->first << "; Valoare: " << itMap->second;
	}

	cout << "Cautare valoare dupa cheie (mapAngajati[4]) -> valoare(nume): " << mapAngajati[4];

	/// MENIU - FISIERE
	cout << "\nApasati orice tasta pentru a trece la meniu...\n";
	cout << "ATENTIE! Ecranul va fi golit!";
	_getch();
	system("cls");

	ofstream fileWrite;
	ifstream fileRead;
	ofstream fileWriteBin;
	ifstream fileReadBin;

	Casier casier1;
	Casier casier2;

	Casier* casieriNoi = new Casier[20];
	int nrCasieriNoi = 0;

	string nume_n;
	int varsta_n;
	int salariu_n;
	int vechime_n;
	float comision_n;
	string sucursala_n;

	int optiune;
	do {
        cout << "\n\n";
        cout << "[][][][][ ][][][][] - M E N I U - [][][][][ ][][][][]" << endl;
        cout << "[1] Scriere in fisier text                         []" << endl;
        cout << "[2] Scriere in fisier binar                        []" << endl;
        cout << "[3] Citire din fisier text                         []" << endl;
        cout << "[4] Citire din fisier binar                        []" << endl;
        cout << "[5] Adaugare casier nou in vectorul de Casieri Noi []" << endl;
        cout << "[6] Afisare vector de Casieri Noi                  []" << endl;
        cout << "[0] Iesire program...                              []" << endl;
        cout << "[o] Introduceti optiunea dorita -> ";
        cin >> optiune;

        system("cls");

        switch(optiune) {
        case 1:
            cout << "\n[1] Scriere in fisier text.\n";
            fileWrite.open("fisier.txt", ios::out);
            fileWrite << cas4;
            fileWrite.close();
            cout << "[] S-a scris in fisier []\n";
            break;
        case 2:
            cout << "\n[2] Scriere in fisier binar.\n";
            fileWriteBin.open("fisier_binar.dat", ios::binary | ios::out);
            fileWriteBin << cas5;
            fileWriteBin.close();
            cout << "[] S-a scris in fisier []\n";
            break;
        case 3:
            cout << "\n[3] Citire din fisier text.\n";
            fileRead.open("fisier.txt", ios::in);
            fileRead >> casier1;
            cout << "Obiect citit din fisier: " << endl << casier1;
            fileRead.close();
            break;
        case 4:
            cout << "\n[4] Citire din fisier binar.\n";
            fileReadBin.open("fisier_bin.dat", ios::binary | ios::in);
            fileReadBin >> casier2;
            cout << "Obiect citit din fisier: " << endl << casier2;
            fileReadBin.close();
            break;
        case 5:
            cout << "\n[5] Adaugare casier nou in vectorul de Casieri Noi\n";
            cout << "Introduceti datele casierului:\n";
            cout << "Nume: "; cin >> nume_n;
            cout << "Varsta: "; cin >> varsta_n;
            cout << "Salariu: "; cin >> salariu_n;
            cout << "Vechime: "; cin >> vechime_n;
            cout << "Comision: "; cin >> comision_n;
            cout << "Sucursala: "; cin >> sucursala_n;

            casieriNoi[nrCasieriNoi].setNume(nume_n);
            casieriNoi[nrCasieriNoi].setVarsta(varsta_n);
            casieriNoi[nrCasieriNoi].setSalariu(salariu_n);
            casieriNoi[nrCasieriNoi].setVechime(vechime_n);
            casieriNoi[nrCasieriNoi].setComision(comision_n);
            casieriNoi[nrCasieriNoi].setSucursala(sucursala_n);

            nrCasieriNoi++;
            break;
        case 6:
            cout << "\n[6] Afisare vector de Casieri Noi\n";
            for(int i = 0; i < nrCasieriNoi; i++) {
                cout << "\nCasierul " << i+1 << ":\n";
                if(nrCasieriNoi == 0) {
                    cout << "\nVectorul de Casieri Noi este momentan gol. Adaugati casieri noi folosind optiunea 5.\n";
                    break;
                }
                casieriNoi[i].afisare();
            }
            break;
        case 0:
            cout << "\n[0] Iesire program...\n";
            break;
        default:
            cout << "Optiune inexitenta! Va rugam sa introduceti alta optiune -> ";
            cin >> optiune;
            break;
        }

	}while(optiune!=0);


	cout << "\nLucrul cu meniul a fost incheiat!\n";

	/// alte apeluri in main

	/// trabuc
	string denumire_t = "Master Trabuc";
	int anFabricatie_t = 2005;
	int nrModele_t = 3;
	string* modele_t = new string[nrModele_t];
	int ratings_t[nrModele_t];
	for (int i = 0; i < nrModele_t; i++) {
		modele_t[i] = "Modelul " + to_string(i+1);
		ratings_t[i] = rand() % 10;
	}

	cout << "\n[-28-] Afisare trabuc cu constructor 1 (trab_1) [][]\n";
	Trabuc* trab_1 = new Trabuc(denumire_t, anFabricatie_t, nrModele_t, modele_t, ratings_t);
	trab_1->afisare();

	cout << "\n[-29-] Afisare trabuc cu constructor 2 (trab_2) [][]\n";
	Trabuc* trab_2 = new Trabuc(nrModele_t, modele_t, ratings_t);
	trab_2->afisare();

	cout << "\n[-30-] Afisare trabuc cu constructor default (trab_3) [][]\n";
	Trabuc* trab_3 = new Trabuc();
	trab_3->afisare();

	cout << "\n[-31-] Afisare trabuc cu constructor 1 (trab_4) [][]\n";
	Trabuc* trab_4 = new Trabuc("Trabuc 4", 2011, 3, modele_t, ratings_t);
	trab_4->afisare();

	/// bricheta
	string denumire_b = "Master Trabuc";
	int anFabricatie_b = 2005;
	int nrModele_b = 3;
	string* modele_b = new string[nrModele_b];
	int ratings_b[nrModele_b];
	for (int i = 0; i < nrModele_b; i++) {
		modele_b[i] = "Modelul " + to_string(i+1);
		ratings_b[i] = rand() % 10;
	}

	cout << "\n[-32-] Afisare bricheta cu constructor 1 (br_1) [][]\n";
	Bricheta* br_1 = new Bricheta(denumire_b, anFabricatie_b, nrModele_b, modele_b, ratings_b);
	br_1->afisare();

	cout << "\n[-33-] Afisare bricheta cu constructor 2 (br_2) [][]\n";
	Bricheta* br_2 = new Bricheta(nrModele_b, modele_b, ratings_b);
	br_2->afisare();

	cout << "\n[-34-] Afisare bricheta cu constructor default (br_3) [][]\n";
	Bricheta* br_3 = new Bricheta();
	br_3->afisare();

	cout << "\n[-35-] Afisare bricheta cu constructor 1 (br_4) [][]\n";
	Bricheta* br_4 = new Bricheta("Bricheta 4", 2011, 3, modele_b, ratings_b);
	br_4->afisare();


	/// DEZALOCARI DE MEMORIE
	delete tab_1;
	delete tab_2;
	delete tab_3;
	delete tab_4;
	delete &tab_5;
	delete &tab_6;
	delete &tab_7;

	delete &raft;
	delete &trab_aromat;

	delete &cas1;
	delete &cas2;

	pers.~Personal();

	delete trab_1;
	delete trab_2;
	delete trab_3;
	delete trab_4;
	delete br_1;
	delete br_2;
	delete br_3;
	delete br_4;

	cout << "\n\n\nApasati orice tasta pentru a termina aplicatia!\n";
	_getch();
    return 0;
}
