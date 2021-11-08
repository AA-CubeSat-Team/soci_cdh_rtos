function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\Nick's PC\\Documents\\GitHub\\soci-gnc\\Build\\FSW_Lib0_ert_rtw\\FSW_Lib0.c",
	size: 72};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Users\\Nick's PC\\Documents\\GitHub\\soci-gnc\\Build\\FSW_Lib0_ert_rtw\\FSW_Lib0.c",
	size: 5};
	 this.metricsArray.var["rtU"] = {file: "C:\\Users\\Nick's PC\\Documents\\GitHub\\soci-gnc\\Build\\FSW_Lib0_ert_rtw\\FSW_Lib0.c",
	size: 207};
	 this.metricsArray.var["rtY"] = {file: "C:\\Users\\Nick's PC\\Documents\\GitHub\\soci-gnc\\Build\\FSW_Lib0_ert_rtw\\FSW_Lib0.c",
	size: 72};
	 this.metricsArray.fcn["FSW_Lib0_initialize"] = {file: "C:\\Users\\Nick's PC\\Documents\\GitHub\\soci-gnc\\Build\\FSW_Lib0_ert_rtw\\FSW_Lib0.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["FSW_Lib0_step0"] = {file: "C:\\Users\\Nick's PC\\Documents\\GitHub\\soci-gnc\\Build\\FSW_Lib0_ert_rtw\\FSW_Lib0.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["FSW_Lib0_step1"] = {file: "C:\\Users\\Nick's PC\\Documents\\GitHub\\soci-gnc\\Build\\FSW_Lib0_ert_rtw\\FSW_Lib0.c",
	stack: 4,
	stackTotal: 4};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="FSW_Lib0_metrics.html">Global Memory: 356(bytes) Maximum Stack: 4(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
