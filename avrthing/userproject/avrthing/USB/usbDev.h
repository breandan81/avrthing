#ifdef __GNUG__
class usbDev {
	public:
	usbDev();
	virtual void ConfigChanged(void) = 0;
	virtual void ControlRequest(void) = 0;
	virtual void StartOfFrame(void) = 0;
	virtual void USBTask(void) = 0;
};
#endif
