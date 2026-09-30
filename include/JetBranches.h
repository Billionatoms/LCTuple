/*
 * =====================================================================================
 *
 *       Filename:  JetBranches.h
 *
 *    Description:  JetBranches holds branches created from a jet collection
 *					created by Satoru Jet Finder processor.
 *					JetBranches has two steerable parameters which are optionally
 *					set in the steering file:
 *					- writeExtraParameters: if set to TRUE, the fill function
 *					calculates some extra parameters using parameters provided
 *					by the jet finding algorithm. Default value is FALSE.
 *					See class data members for a list of extra parameters.
 *					- writeTaggingParameters: if set to TRUE, the fill function
 *					creates branches for jet parameters coming form flavor tagging
 *					processor. If no flavor tagging processr is used, this should
 *					be set to FALSE to prevent errors. Default value is FALSE.
 *					See class data members for a list of extra parameters.
 *
 *        Version:  1.0
 *        Created:  05/26/2015 02:35:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Claude Duerig, Felix Mueller, Aliakbar Ebrahimi 
 *   Organization:  DESY
 *
 * =====================================================================================
 */

#ifndef JetBranches_h
#define JetBranches_h 1

/* #####   HEADER FILE INCLUDES   ################################################### */
#include <vector>
#include "LCTupleConf.h" 
#include "UTIL/PIDHandler.h"

#include "CollectionBranches.h"


class TTree ;

namespace EVENT{
  class LCCollection ;
  class LCCEvent ;
}

/** JetBranches holds branches created from a ReconstructedParticle collection
 * 
 * @author F. Gaede, DESY
 * @version $Id: JetBranches.h 4433 2013-01-24 13:09:57Z boehmej $
 */


/*
 * =====================================================================================
 *        Class:  JetBranches
 *  Description:  holds branches created by a SatoruJetFinder processor
 * =====================================================================================
 */
class JetBranches : public CollectionBranches
{
   public:
	  /* ====================  LIFECYCLE     ======================================= */
      JetBranches () {};                        /* constructor */
      JetBranches(const JetBranches&) = delete ;
      JetBranches& operator=(const JetBranches&) = delete ;
	  virtual ~JetBranches() {} ;               /* Destructor */

	  /* ====================  ACCESSORS     ======================================= */

	  // Following two functions are used to access parameters set in a steering file
	  void writeExtraParameters(bool setextraparameters){ _writeExtraParameters = setextraparameters; };
	  void writeTaggingParameters(bool settaggingparameters){ _writeTaggingParameters = settaggingparameters; };
	  void writeDaughtersParameters(bool setdaughtersparameters){ _writeDaughtersParameters = setdaughtersparameters; };
	  void writeDaughtersCovariance(bool setdaughterscovariance){ _writeDaughtersCovariance = setdaughterscovariance; };

	  /* ====================  MUTATORS      ======================================= */

	  /* ====================  OPERATORS     ======================================= */

	  virtual void initBranches( TTree* tree, const std::string& prefix="" ) ; //const char*  prefix=0) ;
	  virtual void fill(const EVENT::LCCollection* col, EVENT::LCEvent* evt ) ;

   private:
	  /* ====================  METHODS       ======================================= */

	  /* ====================  DATA MEMBERS  ======================================= */

	  bool _writeExtraParameters {} ;               /* Whether to write calculated parameters */
          bool _writeTaggingParameters {} ;             /* Whether to write parameters from tagging processor */
          bool _writeDaughtersParameters {} ;             /* Whether to write daughters */
          bool _writeDaughtersCovariance {} ;             /* Whether to write the full daughter track covariance + reference point */

      unsigned int    _njet {} ;                     /* Number of Jets */

	  // Deafault jet parameters
	  float  _jmox[ LCT_JET_MAX ] {} ;             /* Jet X-Momentum */
	  float  _jmoy[ LCT_JET_MAX ] {} ;             /* Jet Y-Momentum */
	  float  _jmoz[ LCT_JET_MAX ] {};             /* Jet Z-Momentum */
	  float  _jmas[ LCT_JET_MAX ] {};             /* Jet Mass */
	  float  _jene[ LCT_JET_MAX ] {};             /* Jet Energy */
	  float  _jcha[ LCT_JET_MAX ] {};             /* Jet Charge */
      float  _jcov0[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 0 */
      float  _jcov1[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 1 */
      float  _jcov2[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 2 */
      float  _jcov3[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 3 */
      float  _jcov4[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 4 */
      float  _jcov5[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 5 */
      float  _jcov6[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 6 */
      float  _jcov7[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 7 */
      float  _jcov8[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 8 */
      float  _jcov9[ LCT_JET_MAX ] {};            /* Jet Covariance matrix element 9 */

	  // Used for tagging parameters
      float  _btag[ LCT_JET_MAX ] {};             /* ? */
      float  _ctag[ LCT_JET_MAX ] {};             /* ? */
      float  _bctag[ LCT_JET_MAX ] {};            /* ? */
      float  _bcat[ LCT_JET_MAX ] {};             /* ? */
      float  _otag[ LCT_JET_MAX ] {};             /* ? */
	  int algo{};                                 /* ? */
	  int ibtag{};                                /* ? */
	  int ictag{};                                /* ? */
	  int iotag{};                                /* ? */
	  int ibcat{};                                /* ? */
	  lcio::PIDHandler *pid{};
      int _jnpid   {};                            /* ? */

	  // Used for extra parameters
	  float  _jevis {};			                /* Jet Visible Energy */
	  float  _jPxvis{};                           /* Jet Momentum (x-component) */
	  float  _jPyvis{};                           /* Jet Momentum (y-component) */
	  float  _jPzvis{};                           /* Jet Momentum (z-component) */
      float  _jPtvis{};                           /* Visible transverse momentum */
	  float  _jmom[ LCT_JET_MAX ]{} ;             /* Jet Total Momentum */
	  float  _jmmax{} ;                           /* Maximum mass of the Jets */
	  float  _jcost[ LCT_JET_MAX ] {};            /* ? */
	  float  _jTheta{};                           /* ? */
      float  _jcosTheta{};                        /* Angle between z-axis and jet */
      float  _jmvis{};                            /* Visible mass */
      float  _jEmiss{};                           /* Missing energy */
      float  _jMmiss{};                           /* Missing Mass */
      float  _jMmissq{};                          /* Missing mass squared */

      unsigned int _njetpfo[ LCT_JET_MAX ] {};             /* Number of PFOs in a jet */
      int _jetpfoori[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs collection indexes for each jet */

      unsigned int _ndaughters[ LCT_JET_MAX ] {};             /* Number of PFOs in a jet */
      unsigned int _ntracks[ LCT_JET_MAX ] {};             /* Number of tracks in a jet */
      unsigned int _nclusters[ LCT_JET_MAX ] {};             /* Number of clusters in a jet */
      float _daughters_PX[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs PX */
      float _daughters_PY[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs PY */
      float _daughters_PZ[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs PZ */
      float _daughters_E[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs E */
      float _daughters_M[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs M */
      float _daughters_Q[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs Q */
      float _daughters_trackD0[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs track D0 */
      float _daughters_trackPhi[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs track Phi */
      float _daughters_trackOmega[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs track Omega */
      float _daughters_trackZ0[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs track Z0 */
      float _daughters_trackTanLambda[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* PFOs track TanLambda */
      /* Diagonal elements of the LCIO track covariance matrix, i.e. the VARIANCES
       * of the five track parameters - not standard deviations. The consumer must
       * take the square root. They are named "Var" rather than "Sigma" precisely
       * so that this cannot be misread; the old daughters_trackSigmaD0/Z0 names
       * claimed a standard deviation but stored a variance.
       *
       * LCIO stores the covariance as the lower triangle of the 5x5 matrix over
       * the parameters ( d0, phi, omega, z0, tan(lambda) )  -- see
       * lcio EVENT/TrackState.h:72-76 and EVENT/Track.h:75-80 :
       *
       *    "Covariance matrix of the track parameters. Stored as lower triangle
       *     matrix where the order of parameters is: d0, phi, omega, z0,
       *     tan(lambda). So we have cov(d0,d0), cov( phi, d0 ), cov( phi, phi), ..."
       *
       * so the packed diagonal indices are:
       *
       *    [ 0] var(d0)       [mm^2]
       *    [ 2] var(phi)      [rad^2]
       *    [ 5] var(omega)    [mm^-2]
       *    [ 9] var(z0)       [mm^2]
       *    [14] var(tanLambda)[dimensionless]
       *
       * The previous code read index [2] for z0, which is var(phi) - a different
       * parameter with different units, ~2900x smaller in this sample.
       */
      float _daughters_trackVarD0[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ;        // cov[ 0] var(d0)        [mm^2]
      float _daughters_trackVarPhi[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ;       // cov[ 2] var(phi)       [rad^2]
      float _daughters_trackVarOmega[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ;     // cov[ 5] var(omega)     [1/mm^2]
      float _daughters_trackVarZ0[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ;        // cov[ 9] var(z0)        [mm^2]
      float _daughters_trackVarTanLambda[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; // cov[14] var(tanLambda) [-]

      /* ----------  diagnostic branches, enabled by JetCollectionDaughtersCovariance  ----------
       * All of the following are written only when _writeDaughtersCovariance is true
       * (processor parameter default false), so existing configurations are unaffected.
       *
       * The LCIO covariance matrix is the lower triangle of the 5x5 matrix over the
       * parameters ( d0, phi, omega, z0, tan(lambda) ), i.e. 15 packed elements:
       *
       *    0 cov(d0,d0)     5 cov(Om,Om)    10 cov(tanL,d0)
       *    1 cov(phi,d0)    6 cov(z0,d0)    11 cov(tanL,phi)
       *    2 cov(phi,phi)   7 cov(z0,phi)   12 cov(tanL,Om)
       *    3 cov(Om,d0)     8 cov(z0,Om)    13 cov(tanL,z0)
       *    4 cov(Om,phi)    9 cov(z0,z0)    14 cov(tanL,tanL)
       *
       * so the diagonal (the variances) sits at 0, 2, 5, 9, 14.
       * See lcio EVENT/TrackState.h:72-76 and EVENT/Track.h:75-80.
       */
      float _daughters_trackCov[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ][ 15 ] {} ; /* full packed track covariance */
      float _daughters_trackRefX[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* track reference point x [mm] */
      float _daughters_trackRefY[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* track reference point y [mm] */
      float _daughters_trackRefZ[ LCT_JET_MAX ][ LCT_JET_PARTICLES_MAX ] {} ; /* track reference point z [mm] */

      /* Number of daughters ACTUALLY written to the arrays, i.e.
       * min( ndaughters, LCT_JET_PARTICLES_MAX ). _ndaughters reports the full
       * jet constituent count, so _ndaughters > _ndaughters_stored means the
       * per-jet arrays were truncated and the excess constituents are absent. */
      unsigned int _ndaughters_stored[ LCT_JET_MAX ] {} ;


}; /* -----  end of class JetBranches  ----- */

#endif
