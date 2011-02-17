#ifndef INTROSTATE_H_
#define INTROSTATE_H_

/* IntroState constants were once macro constants but not used. */
enum IntroState {
	NONE=-1,
	DUNE
	ARRAKIS,	// the planet arrakis... known as dune
	LANDSAND,	// land of sand (home of the spice melange)
	SPICE,		// the spice controls the empire, whoever controls dune, controls the spice
	EMPEROR,	// the emperor has proposed a challange to each of the houses
	EMPTALK,	// The House that produces the most spice, whill control dune. There are no set
			// territories and no rules of engagement
	ARMIES,		// vast armies have arrived

			// now 3 houses fight, for control of dune (no image, blank)

	ATREIDES,	// the noble atreides
	ORDOS,		// the insidious ordos
	HARKONNEN,	// the evil harkonnen
	FIRE,		// only one house will prevail...
	BEGINS,		// your battle for dune begins.. NOW!
}

#endif
