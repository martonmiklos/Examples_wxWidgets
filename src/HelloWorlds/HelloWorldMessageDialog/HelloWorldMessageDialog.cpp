#include <wx/wx.h>

#include "a.xpm"
#include "b.xpm"
#include "a16.xpm"
#include "b32.xpm"

class Application : public wxApp {
  bool OnInit() override {
    auto frame1 = new wxFrame(nullptr, wxID_ANY, "Hello World (message box)");

    wxIconBundle icon_bundle;

    icon_bundle.AddIcon( wxICON(a) );
    icon_bundle.AddIcon( wxICON(a16) );

    frame1->SetIcons(icon_bundle);
    
    auto panel1 = new wxPanel(frame1, wxID_ANY);
    
    auto button1 = new wxButton(panel1, wxID_ANY, "Click me", {10, 10});
    button1->Bind(wxEVT_BUTTON, [](wxCommandEvent&) {
        auto frame2 = new wxFrame(nullptr, wxID_ANY, "Hello World (message box)");

        wxIconBundle icon_bundle;

        icon_bundle.AddIcon( wxICON(b) );
        icon_bundle.AddIcon( wxICON(b32) );
        frame2->SetIcons(icon_bundle);
        frame2->Show();
    });
    
    frame1->Show();
    return true;
  }
};

wxIMPLEMENT_APP(Application);
