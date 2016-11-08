#include "PlotWin.h"
#include "MainFrame.h"

#include <mgl2/mgl.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/dcclient.h>
#include <wx/msgdlg.h> 


PlotWin::PlotWin(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style)
				: wxScrolledWindow(parent, id)

{
	m_pBitmap = NULL;

}

PlotWin::~PlotWin()
{
	if(m_pBitmap != NULL)	delete m_pBitmap;
}
//-----------------------------------------------------------------------------

void PlotWin::plotSomething(std::vector<double>& fd, std::vector<double>& fdSmooth)
{
//	int w,h,x,y;
//	wxClientDC dc(this);
//	dc.GetSize( &w,&h );
//	GetClientSize(&w,&h);   // size of the picture

	mglData yfd(fd.size());
	mglData yfdSmooth(fd.size());
	for(int i=0; i<fd.size(); i++) {
		yfd.a[i] = fd[i];
		yfdSmooth.a[i] = fdSmooth[i];
	}

	mglGraph gr(2000, 400); // class for plot drawing
//	gr.Rotate(50,60); // rotate axis
//	gr.Alpha(true);         // draws something using MathGL
//	gr.Light(true);
	gr.SetRanges(0, 4000, 0, 500);
	gr.Axis();
	gr.Plot(yfd);
//	gr.Box();
//	gr.Light(true); // enable lighting

//	mglGraph gr(w,h);

//	gr.Alpha(true);         // draws something using MathGL
//	gr.Light(true);
//	sample(&gr);

//	gr.WriteFrame("e:\\_sample.png"); //
	int gw, gh;
	gw = gr.GetWidth();
	gh = gr.GetHeight();
	wxImage img(gw, gh, gr.GetRGB(), true);
	
	//wxPaintDC dc(this);         // and draws it
	if(m_pBitmap)  delete m_pBitmap;

	m_pBitmap = new wxBitmap( img );	
	
	SetVirtualSize( gw, gh );

	Refresh();

	MainFrame::myMsgOutput("gw %d, gh %d\n", gw, gh);
//	wxMessageBox(wxT("plotSomething"));

	
}

void PlotWin::OnDraw(wxDC& dc)
{

	if(m_pBitmap)
		dc.DrawBitmap(*m_pBitmap,0,0, false);


}
