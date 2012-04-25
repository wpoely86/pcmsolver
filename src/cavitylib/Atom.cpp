#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

#include "Atom.h"

/*

  Methods for Atom class
  written by Roberto Di Remigio, 2011

*/

Atom::Atom( const string & element, const string & symbol, double charge, 
			double radius, Vector3d & coord, double scaling, const string & colour ) {
  atomElement = element;
  atomSymbol = symbol;
  atomCharge = charge;
  atomRadius = radius;
  atomCoord = coord;
  atomColour = colour;
  atomRadiusScaling = scaling;
}

Atom::Atom( const string & element, const string & symbol, double charge, 
			double radius ) {
  Vector3d Origin(0.0, 0.0, 0.0);
  string colour = "Violet";
  atomElement = element;
  atomSymbol = symbol;
  atomCharge = charge;
  atomRadius = radius;
  atomCoord = Origin;
  atomColour = colour;
  atomRadiusScaling = 1.0;
}


vector<Atom> Atom::initBondi() {
	/*

	  vector<Atom> Bondi() contains the van der Waals radii taken from
	  --- A. Bondi, J. Phys. Chem. 68, 441-451 (1964) ---
  
	*/

	vector<Atom> Bondi(54);
	Vector3d Origin;

	Origin << 0.0, 0.0, 0.0;

// ------------------------------------------------------------
	Bondi[0] = Atom("Hydrogen", "H", 1.0, 1.20, Origin, 1.0);
	Bondi[1] = Atom("Helium", "He", 2.0, 1.40, Origin, 1.0);
	Bondi[2] = Atom("Lithium", "Li", 3.0, 0.0, Origin, 1.0);
	Bondi[3] = Atom("Beryllium", "Be", 4.0, 0.0, Origin, 1.0);
	Bondi[4] = Atom("Boron", "B", 5.0, 0.0, Origin, 1.0);
	Bondi[5] = Atom("Carbon", "C", 6.0, 1.70, Origin, 1.0);
	Bondi[6] = Atom("Nitrogen", "N", 7.0, 1.55, Origin, 1.0);
	Bondi[7] = Atom("Oxygen", "O", 8.0, 1.52, Origin, 1.0);
	Bondi[8] = Atom("Fluorine", "F", 9.0, 1.47, Origin, 1.0);
	Bondi[9] = Atom("Neon", "Ne", 10.0, 1.54, Origin, 1.0);
	Bondi[10] = Atom("Sodium", "Na", 11.0, 0.0, Origin, 1.0);
	Bondi[11] = Atom("Magnesium", "Mg", 12.0, 0.0, Origin, 1.0);
	Bondi[12] = Atom("Aluminium", "Al", 13.0, 0.0, Origin, 1.0);
	Bondi[13] = Atom("Silicon", "Si", 14.0, 2.10, Origin, 1.0);
	Bondi[14] = Atom("Phosphorus", "P", 15.0, 1.80, Origin, 1.0);
	Bondi[15] = Atom("Sulphur", "S", 16.0, 1.80, Origin, 1.0);
	Bondi[16] = Atom("Chlorine", "Cl", 17.0, 1.75, Origin, 1.0);
	Bondi[17] = Atom("Argon", "Ar", 18.0, 1.88, Origin, 1.0);
	Bondi[18] = Atom("Potassium", "K", 19.0, 0.0, Origin, 1.0);
	Bondi[19] = Atom("Calcium", "Ca", 20.0, 0.0, Origin, 1.0);
	Bondi[20] = Atom("Scandium", "Sc", 21.0, 0.0, Origin, 1.0);
	Bondi[21] = Atom("Titanium", "Ti", 22.0, 0.0, Origin, 1.0);
	Bondi[22] = Atom("Vanadium", "V",  23.0, 0.0, Origin, 1.0);
	Bondi[23] = Atom("Chromium", "Cr", 24.0, 0.0, Origin, 1.0);
	Bondi[24] = Atom("Manganese", "Mn", 25.0, 0.0, Origin, 1.0);
	Bondi[25] = Atom("Iron", "Fe", 26.0, 0.0, Origin, 1.0);
	Bondi[26] = Atom("Cobalt", "Co", 27.0, 0.0, Origin, 1.0);
	Bondi[27] = Atom("Nickel", "Ni", 28.0, 0.0, Origin, 1.0);
	Bondi[28] = Atom("Copper", "Cu", 29.0, 0.0, Origin, 1.0);
	Bondi[29] = Atom("Zinc", "Zn", 30.0, 0.0, Origin, 1.0);
	Bondi[30] = Atom("Gallium", "Ga", 31.0, 0.0, Origin, 1.0);
	Bondi[31] = Atom("Germanium", "Ge", 32.0, 0.0, Origin, 1.0);
	Bondi[32] = Atom("Arsenic", "As", 33.0, 1.85, Origin, 1.0);
	Bondi[33] = Atom("Selenium", "Se", 34.0, 1.90, Origin, 1.0);
	Bondi[34] = Atom("Bromine", "Br", 35.0, 1.85, Origin, 1.0);
	Bondi[35] = Atom("Krypton", "Kr", 36.0, 2.02, Origin, 1.0);
	Bondi[36] = Atom("Rubidium", "Rb", 37.0, 0.0, Origin, 1.0);
	Bondi[37] = Atom("Strontium", "Sr", 38.0, 0.0, Origin, 1.0);
	Bondi[38] = Atom("Yttrium", "Y", 39.0, 0.0, Origin, 1.0);
	Bondi[39] = Atom("Zirconium", "Zr", 40.0, 0.0, Origin, 1.0);
	Bondi[40] = Atom("Niobium", "Nb", 41.0, 0.0, Origin, 1.0);
	Bondi[41] = Atom("Molybdenum", "Mo", 42.0, 0.0, Origin, 1.0);
	Bondi[42] = Atom("Technetium", "Tc", 43.0, 0.0, Origin, 1.0);
	Bondi[43] = Atom("Ruthenium", "Ru", 44.0, 0.0, Origin, 1.0);
	Bondi[44] = Atom("Rhodium", "Rh", 45.0, 0.0, Origin, 1.0);
	Bondi[45] = Atom("Palladium", "Pd", 46.0, 0.0, Origin, 1.0);
	Bondi[46] = Atom("Silver", "Ag", 47.0, 0.0, Origin, 1.0);
	Bondi[47] = Atom("Cadmium", "Cd", 48.0, 0.0, Origin, 1.0);
	Bondi[48] = Atom("Indium", "In", 49.0, 0.0, Origin, 1.0);
	Bondi[49] = Atom("Tin", "Sn", 50.0, 0.0, Origin, 1.0);
	Bondi[50] = Atom("Antimony", "Sb", 51.0, 0.0, Origin, 1.0);
	Bondi[51] = Atom("Tellurium", "Te", 52.0, 2.06, Origin, 1.0);
	Bondi[52] = Atom("Iodine", "I",  53.0, 1.98, Origin, 1.0);
	Bondi[53] = Atom("Xenon", "Xe", 54.0, 2.16, Origin, 1.0);
// ------------------------------------------------------------
	return Bondi;
}

