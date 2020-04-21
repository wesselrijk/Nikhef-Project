// Macro for reading the file myster_file and its TTree component

void macro () {

    // Load the root file and build a tree
    TFile *file = TFile::Open("mystery_file.root");
    TTree *tree =(TTree*)file->Get("hits_tree");
    
    // Show contents of tree
    tree->Print();
    tree->Show();
    
    // MakeCode builds a skeleton for TTree
    // tree->MakeCode();
    
    // Draw some nice plots
    auto c = new TCanvas;
    c->SetLogy();
    tree->Draw("genpart_energy");
    auto c1 = new TCanvas;
    tree->Draw("hit_global_x:hit_global_y:hit_global_z","","",1);
    auto c2 = new TCanvas;
    tree->Draw("hit_local_x:hit_local_y","","",1);
    auto c3 = new TCanvas;
    tree->Draw("hit_local_x_error:hit_local_y_error","","",1);

}

int main() {
    macro();
}

