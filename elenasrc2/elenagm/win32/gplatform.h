//---------------------------------------------------------------------------
//		E L E N A   P r o j e c t:  ELENA Graphic Engine
//
//                                              (C)2017, by Alexei Rakov
//---------------------------------------------------------------------------

#ifndef elenagm_graphicsH
#define elenagm_graphicsH 1

class GraphicPlatform
{
public:
	virtual ~GraphicPlatform() {}

	virtual void Init(HWND hWnd) = 0;
	virtual void OnRender(HWND hWnd) = 0;
	virtual void OnDestroy() = 0;
};

#endif //  elenagm_graphicsH

