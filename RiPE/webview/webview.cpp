/////////////////////////////////////////////////////////////////////////////
// Name:        webview.cpp
// Purpose:     Common interface and events for web view component
// Author:      Marianne Gagnon
// Id:          $Id$
// Copyright:   (c) 2010 Marianne Gagnon
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "webview.h"

#include "wxOSXWebkitCtrl/webkit.h"
#include "wxGtkWebKitCtrl/wxgtkwebkitctrl.h"
#include "wxIETest2/wxiepanel.h"

IMPLEMENT_DYNAMIC_CLASS(wxWebNavigationEvent, wxCommandEvent)

wxDEFINE_EVENT( wxEVT_COMMAND_WEB_VIEW_NAVIGATING, wxWebNavigationEvent );
wxDEFINE_EVENT( wxEVT_COMMAND_WEB_VIEW_NAVIGATED, wxWebNavigationEvent );
wxDEFINE_EVENT( wxEVT_COMMAND_WEB_VIEW_LOADED, wxWebNavigationEvent );
wxDEFINE_EVENT( wxEVT_COMMAND_WEB_VIEW_ERROR, wxWebNavigationEvent );

// static
wxWebView* wxWebView::GetNew(wxWebViewBackend backend)
{
    switch (backend)
    {
        #if wxHAVE_WEB_BACKEND_OSX_WEBKIT
            case wxWEB_VIEW_BACKEND_OSX_WEBKIT:
                return new wxOSXWebKitCtrl();
        #endif

        #if wxHAVE_WEB_BACKEND_GTK_WEBKIT
            case wxWEB_VIEW_BACKEND_GTK_WEBKIT:
                return new wxGtkWebKitCtrl();
        #endif

        #if wxHAVE_WEB_BACKEND_IE
            case wxWEB_VIEW_BACKEND_IE:
                return new wxIEPanel();
        #endif

        case wxWEB_VIEW_BACKEND_DEFAULT:

            #if wxHAVE_WEB_BACKEND_OSX_WEBKIT
            return new wxOSXWebKitCtrl();
            #endif

            #if wxHAVE_WEB_BACKEND_GTK_WEBKIT
            return new wxGtkWebKitCtrl();
            #endif

            #if wxHAVE_WEB_BACKEND_IE
            return new wxIEPanel();
            #endif

        // fall-through intended
        default:
            return NULL;
    }
}

// static
wxWebView* wxWebView::GetNew(wxWindow* parent,
       wxWindowID id,
       const wxString& url,
       const wxPoint& pos,
       const wxSize& size,
       wxWebViewBackend backend,
       long style,
       const wxString& name)
{
    switch (backend)
    {
        #if wxHAVE_WEB_BACKEND_OSX_WEBKIT
            case wxWEB_VIEW_BACKEND_OSX_WEBKIT:
                return new wxOSXWebKitCtrl(parent, id, url, pos, size, style, name);
        #endif

        #if wxHAVE_WEB_BACKEND_GTK_WEBKIT
            case wxWEB_VIEW_BACKEND_GTK_WEBKIT:
                return new wxGtkWebKitCtrl(parent, id, url, pos, size, style, name);
        #endif

        #if wxHAVE_WEB_BACKEND_IE
            case wxWEB_VIEW_BACKEND_IE:
                return new wxIEPanel(parent, id, url, pos, size, style, name);
        #endif

        case wxWEB_VIEW_BACKEND_DEFAULT:

            #if wxHAVE_WEB_BACKEND_OSX_WEBKIT
            return new wxOSXWebKitCtrl(parent, id, url, pos, size, style, name);
            #endif

            #if wxHAVE_WEB_BACKEND_GTK_WEBKIT
            return new wxGtkWebKitCtrl(parent, id, url, pos, size, style, name);
            #endif

            #if wxHAVE_WEB_BACKEND_IE
            return new wxIEPanel(parent, id, url, pos, size, style, name);
            #endif

        // fall-through intended
        default:
            return NULL;
    }
}
