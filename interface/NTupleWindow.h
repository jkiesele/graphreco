/*
 * NTupleWindow.h
 *
 *  Created on: 26 Sep 2019
 *      Author: jkiesele
 */

#ifndef SRC_RECOHGCAL_GRAPHRECO_INTERFACE_NTUPLEWINDOW_H_
#define SRC_RECOHGCAL_GRAPHRECO_INTERFACE_NTUPLEWINDOW_H_

#include "../interface/WindowBase.h"
#include <algorithm>
#include <unordered_map>

class NTupleWindow: public WindowBase {
public:

    NTupleWindow(float centerEta, float centerPhi, float outerRegionDEta, float outerRegionDPhi,
            float innerRegionDEta, float innerRegionDPhi);

    static void createTreeBranches(TTree* t);

    //0 associate all rechits etc

    void fillFeatureArrays();
    //1
    void fillTruthArrays();
    //2
    void assignTreePointers() ;
    void flattenRechitFeatures();

    //3: tree->Fill();

    //4
    void clear();

    static std::vector<NTupleWindow> createWindows(size_t nSegmentsPhi,
            size_t nSegmentsEta, double minEta, double maxEta, double frameWidthEta,
            double frameWidthPhi);



private:
    NTupleWindow(){}

    void createDetIDHitAssociation();
    void calculateSimclusterFeatures();
    void calculateTruthFractions();
    void fillTruthAssignment();

    //temporary for (layer cluster) fraction calculation. detID to hit index and fraction
    std::unordered_map<DetId, std::pair<size_t, float>> detIDHitAsso_;


    //can be layer clusters or rechits according to mode
    std::vector<std::vector<float> >  hitFeatures_; //this includes tracks!
    std::vector<float> recHitEnergy_;
    std::vector<float> recHitEta_;
    std::vector<float> recHitRelPhi_;
    std::vector<float> recHitTheta_;
    std::vector<float> recHitMag_;
    std::vector<float> recHitX_;
    std::vector<float> recHitY_;
    std::vector<float> recHitZ_;
    std::vector<float> recHitDetID_;
    std::vector<float> recHitTime_;
    std::vector<float> recHitID_;
    std::vector<float> recHitPad_;

    std::vector<std::vector<float> >  truthHitFractions_;


    //hit (rechit or layer cluster) assigned to exactly one simcluster with index
    std::vector<int>                 truthHitAssignementIdx_;
    //truth energy of assigned simcluster
    std::vector<float>               truthHitAssignedEnergies_;
    //truth eta of assigned simcluster
    std::vector<float>               truthHitAssignedEtas_;
    //truth delta-phi to window center of assigned simcluster
    std::vector<float>               truthHitAssignedPhis_;
    std::vector<float>               truthHitAssignedInner_;
    //truth energy of assigned simcluster
    std::vector<std::vector<int> >   truthHitAssignedPIDs_;

    std::vector<int>     truthSimclusterIdx_;
    std::vector<std::vector<int> >    truthSimclusterPIDs_;
    std::vector<float>   truthSimclusterEnergies_;
    std::vector<float>   truthSimclusterEtas_;
    std::vector<float>   truthSimclusterPhis_;
    std::vector<float>   truthSimclusterT_;
    std::vector<float>   truthSimclusterDirPhi_;
    std::vector<float>   truthSimclusterDirEta_;
    std::vector<float>   truthSimclusterDirR_;
    std::vector<float>   truthSimclusterInnerWindow_;

    //some globals mostly for plotting

    float windowEta_, windowPhi_;

    static const bool flattenRechitFeatures_ = true;
    enum rhLables {kEnergy, kEta, kRelPhi, kTheta, kMag, kx, ky, kz, kDetid, kTime, kId, kPad};
    //static pointers to create branches and fill tree
    static std::vector<std::vector<float>> * sp_hitFeatures_;
    static std::vector<float> * sp_recHitEnergy_;
    static std::vector<float> * sp_recHitEta_;
    static std::vector<float> * sp_recHitRelPhi_;
    static std::vector<float> * sp_recHitTheta_;
    static std::vector<float> * sp_recHitMag_;
    static std::vector<float> * sp_recHitX_;
    static std::vector<float> * sp_recHitY_;
    static std::vector<float> * sp_recHitZ_;
    static std::vector<float> * sp_recHitDetID_;
    static std::vector<float> * sp_recHitTime_;
    static std::vector<float> * sp_recHitID_;
    static std::vector<float> * sp_recHitPad_;
    //static std::vector<float> * sp_trackFeatures_;

    static std::vector<std::vector<float> > * sp_truthHitFractions_;
    static std::vector<int>                 * sp_truthHitAssignementIdx_;
    static std::vector<float>               * sp_truthHitAssignedEnergies_;
    static std::vector<float>               * sp_truthHitAssignedEtas_;
    static std::vector<float>               * sp_truthHitAssignedPhis_;
    static std::vector<std::vector<int> >   * sp_truthHitAssignedPIDs_;
    static std::vector<float> * sp_truthHitAssignedInner_;

    static std::vector<int>    * sp_truthSimclusterIdx_;
    static std::vector<std::vector<int> >   * sp_truthSimclusterPIDs_;
    static std::vector<float>  * sp_truthSimclusterEnergies_;
    static std::vector<float>  * sp_truthSimclusterEtas_;
    static std::vector<float>  * sp_truthSimclusterPhis_;
    static std::vector<float>  * sp_truthSimclusterT_;
    static std::vector<float>  * sp_truthSimclusterInnerWindow_;

    static std::vector<float>  * sp_truthSimclusterDirEta_;
    static std::vector<float>  * sp_truthSimclusterDirPhi_;
    static std::vector<float>  * sp_truthSimclusterDirR_;

    static float * sp_windowEta_;
    static float * sp_windowPhi_;

};




#endif /* SRC_RECOHGCAL_GRAPHRECO_INTERFACE_NTUPLEWINDOW_H_ */
