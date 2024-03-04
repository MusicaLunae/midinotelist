#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif

#ifndef __GUI_H
#define __GUI_H

class MainApp : public wxApp
{
    public:
    virtual bool OnInit();
};

class MainFrame : public wxFrame
{
    public:
    MainFrame (const wxString &title, const wxPoint &pos, const wxSize &size);

    wxMenuBar *MainMenu;
    
    void Quit(wxCommandEvent& event);
    void NewTable(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()

};

enum
{
    GRID_Main = wxID_HIGHEST + 1,
    MENU_NewTable,
    MENU_Quit
};

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(MENU_NewTable, MainFrame::NewTable)
    EVT_MENU(MENU_Quit, MainFrame::Quit)
END_EVENT_TABLE()


#endif