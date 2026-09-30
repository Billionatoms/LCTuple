#ifndef TrackBranches_h
#define TrackBranches_h 1

#include "LCTupleConf.h" 
#include "CollectionBranches.h"

class TTree ;

namespace EVENT{
  class LCCollection ;
  class LCCEvent ;
}

/** TrackBranches holds branches created from a Track collection
 * 
 * @author F. Gaede, DESY
 * @version $Id$
 */

class TrackBranches : public CollectionBranches {
  
public:
  
  TrackBranches() {} ;

  // Following function is used to access parameters set in a steering file
  void writeTrkStatesParameters(bool param){ _writeTrkStatesParameters = param; };
  void writeTrkHitsParameters(bool param){ _writeTrkHitsParameters = param; };
  
  virtual void initBranches( TTree* tree, const std::string& prefix="" ) ; 
  
  virtual void fill(const EVENT::LCCollection* col, EVENT::LCEvent* evt ) ;
  
  virtual ~TrackBranches() {} ;

private:
  
  bool _writeTrkStatesParameters {} ;     /* Whether to write track states parameters */
  bool _writeTrkHitsParameters {} ;       /* Whether to write track hits parameters */

  int   _ntrk  {} ; // number of tracks

  int   _trori[ LCT_TRACK_MAX ]  {} ;  // track index: ext<CollID> 
  int   _trtyp[ LCT_TRACK_MAX ]  {} ;  // type
  float _trch2[ LCT_TRACK_MAX ]  {} ;  // chi2
  int   _trndf[ LCT_TRACK_MAX ]  {} ;  // ndf
  float _tredx[ LCT_TRACK_MAX ]  {} ;  // dEdx
  float _trede[ LCT_TRACK_MAX ]  {} ;  // dEdxError(
  float _trrih[ LCT_TRACK_MAX ]  {} ;  // RadiusOfInnermostHit
  int   _trnts[ LCT_TRACK_MAX ]  {} ;  // number of states
  int   _trthn[ LCT_TRACK_MAX ]  {} ;  // number of hits
  int   _trtvhn[ LCT_TRACK_MAX ] {} ;  // number of vertex hits
  int   _trtihn[ LCT_TRACK_MAX ] {} ;  // number of inner hits
  int   _trtohn[ LCT_TRACK_MAX ] {} ;  // number of outer hits
  int   _trtnh[ LCT_TRACK_MAX ]  {} ;  // number of holes 
  int   _trtout[ LCT_TRACK_MAX ] {} ;  // number of outliers (#hit-ndf/2)
  float _trome[ LCT_TRACK_MAX ]  {} ;  // omega at IP state
  float _trtnl[ LCT_TRACK_MAX ]  {} ;  // tan lambda at IP state
  float _trthe[ LCT_TRACK_MAX ]  {} ;  // theta at IP state
  float _trdze[ LCT_TRACK_MAX ]  {} ;  // d0 at IP state
  float _trzze[ LCT_TRACK_MAX ]  {} ;  // z0 at IP state
  float _trphi[ LCT_TRACK_MAX ]  {} ;  // phi at IP state
  //float _trcov[ LCT_TRACK_MAX ] [15]  {} ; // covariance matrix at IP state (i.e. cov)
  /* Variances of the LCIO track parameters at the AtIP track state.
   * The packed-index arithmetic below was always right (0,2,5,9,14 are the
   * lower-triangle diagonals); what was wrong were the NAMES: they assumed the
   * ATLAS/ACTS parameter order ( l0, l1, phi, theta, q/p ) whereas LCIO uses
   * ( d0, phi, omega, z0, tanLambda ) -- EVENT/TrackState.h:72-76. So the branch
   * called trk_sigmal1 was var(phi), trk_sigmaphi was var(omega), trk_sigmatheta
   * was var(z0) and trk_sigmaqoverp was var(tanLambda).
   * Note theta and q/p are NOT LCIO track parameters: their variances require
   * Jacobian propagation from omega and tanLambda and cannot be read off a
   * single element, which is why those two branches are gone rather than fixed.
   * These are VARIANCES, not standard deviations.
   */
  float _trk_varD0[ LCT_TRACK_MAX ]  {} ;         // cov[ 0] var(d0)        [mm^2]
  float _trk_varPhi[ LCT_TRACK_MAX ]  {} ;        // cov[ 2] var(phi)       [rad^2]
  float _trk_varOmega[ LCT_TRACK_MAX ]  {} ;      // cov[ 5] var(omega)     [1/mm^2]
  float _trk_varZ0[ LCT_TRACK_MAX ]  {} ;         // cov[ 9] var(z0)        [mm^2]
  float _trk_varTanLambda[ LCT_TRACK_MAX ]  {} ;  // cov[14] var(tanLambda) [-]

  // track states parameters
  int   _ntrst  {} ;                   // total number of track states  
  int   _trfts[ LCT_TRACK_MAX ]  {} ;  // track state index: ext<CollIndex>()
  int   _trsip[ LCT_TRACK_MAX ]  {} ;  // track state index atIP
  int   _trsfh[ LCT_TRACK_MAX ]  {} ;  // track state index atFirstHit
  int   _trslh[ LCT_TRACK_MAX ]  {} ;  // track state index atLastHit
  int   _trsca[ LCT_TRACK_MAX ]  {} ;  // track state index atCalorimeter
  int   _tsloc[ LCT_TRACKSTATE_MAX ]  {} ; // location
  float _tsdze[ LCT_TRACKSTATE_MAX ]  {} ; // D0
  float _tsphi[ LCT_TRACKSTATE_MAX ]  {} ; // phi
  float _tsome[ LCT_TRACKSTATE_MAX ]  {} ; // omega
  float _tszze[ LCT_TRACKSTATE_MAX ]  {} ; // Z0
  float _tstnl[ LCT_TRACKSTATE_MAX ]  {} ; // TanLambda
  float _tsrpx[ LCT_TRACKSTATE_MAX ]  {} ; // x
  float _tsrpy[ LCT_TRACKSTATE_MAX ]  {} ; // y
  float _tsrpz[ LCT_TRACKSTATE_MAX ]  {} ; // z
  float _tscov[ LCT_TRACKSTATE_MAX ][15]  {} ; // covariance matrix 
 
  // track hits parameters
  int   _trthi[ LCT_TRACK_MAX ][50]  {} ; // track hit indices     
  int   _trthd[ LCT_TRACK_MAX ][50]  {} ; // track hit subdetector 
  int   _trshn[ LCT_TRACK_MAX ][12]  {} ; // track hit per subdetector 
  float _trthx[ LCT_TRACK_MAX ][50]  {} ; // track hit x coord 
  float _trthy[ LCT_TRACK_MAX ][50]  {} ; // track hit y coord 
  float _trthz[ LCT_TRACK_MAX ][50]  {} ; // track hit z coord 

  // EVENT::TrackVec _tracks ;
  // EVENT::TrackerHitVec _hits ;
  
} ;

#endif