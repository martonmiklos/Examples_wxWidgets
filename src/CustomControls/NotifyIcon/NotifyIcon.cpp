#include "Gammasoft.xpm"
#include "wxNotifyIcon.h"

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "NotifyIcon example", wxDefaultPosition, {300, 300}) {
      notifyIcon1.SetIcon({GammasoftIcon});
      notifyIcon1.Bind(wxEVT_TASKBAR_LEFT_DCLICK, [&](wxTaskBarIconEvent& event) {
        Show(!IsShown());
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "Double click on Gammasoft tray icon\nto show or hide this frame.", {10, 10});
    wxNotifyIcon notifyIcon1;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
