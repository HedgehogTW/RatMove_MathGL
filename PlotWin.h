#ifndef PLOTWIN_H
#define PLOTWIN_H

#include <wx/scrolwin.h>
class PlotWin : public wxScrolledWindow
{
public:
	PlotWin(wxWindow *parent, wxWindowID id=-1, 
         const wxPoint &pos=wxDefaultPosition, 
		 const wxSize &size=wxDefaultSize, long style=wxHSCROLL|wxVSCROLL);
	~PlotWin();
	
	void plotSomething(std::vector<double>& fd, std::vector<double>& fdSmooth);
	void OnDraw(wxDC& dc);
	
private:	

	wxBitmap* m_pBitmap;

};

#endif // PLOTWIN_H
