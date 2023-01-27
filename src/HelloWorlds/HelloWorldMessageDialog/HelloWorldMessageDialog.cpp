#include <wx/wx.h>

#include "a.xpm"
#include "b.xpm"

class Application : public wxApp {
  bool OnInit() override {
    auto frame1 = new wxFrame(nullptr, wxID_ANY, "Hello World (message box)");
    auto icon = wxICON(a);
    frame1->SetIcon(icon);
    
    auto panel1 = new wxPanel(frame1, wxID_ANY);
    
    auto button1 = new wxButton(panel1, wxID_ANY, "Click me", {10, 10});
    button1->Bind(wxEVT_BUTTON, [](wxCommandEvent&) {
        auto frame2 = new wxFrame(nullptr, wxID_ANY, "Hello World (message box)");
        auto icon = wxICON(b);
        frame2->SetIcon(icon);
        frame2->Show();
    });
    
    frame1->Show();
    return true;
  }
};

wxIMPLEMENT_APP(Application);
