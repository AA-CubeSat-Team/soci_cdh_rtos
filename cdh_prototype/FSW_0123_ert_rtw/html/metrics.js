function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 80};
	 this.metricsArray.var["rtInf"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 8};
	 this.metricsArray.var["rtInfF"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 4};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 4};
	 this.metricsArray.var["rtMinusInf"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 8};
	 this.metricsArray.var["rtMinusInfF"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 4};
	 this.metricsArray.var["rtNaN"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 8};
	 this.metricsArray.var["rtNaNF"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 4};
	 this.metricsArray.var["rtU"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 160};
	 this.metricsArray.var["rtY"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	size: 72};
	 this.metricsArray.fcn["FSW_0123_initialize"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 0,
	stackTotal: 24};
	 this.metricsArray.fcn["FSW_0123_step"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 248,
	stackTotal: 248};
	 this.metricsArray.fcn["cos"] = {file: "C:\\Program Files\\MATLAB\\R2018b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fabs"] = {file: "C:\\Program Files\\MATLAB\\R2018b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtGetInf"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 20,
	stackTotal: 24};
	 this.metricsArray.fcn["rtGetInfF"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetMinusInf"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 20,
	stackTotal: 24};
	 this.metricsArray.fcn["rtGetMinusInfF"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetNaN"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 20,
	stackTotal: 24};
	 this.metricsArray.fcn["rtGetNaNF"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtIsInf"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsInfF"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaN"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 13,
	stackTotal: 17};
	 this.metricsArray.fcn["rtIsNaNF"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rt_InitInfAndNaN"] = {file: "C:\\Users\\Nick\\Documents\\FSW_Builds\\Build_01042022\\FSW_0123_ert_rtw\\FSW_0123.c",
	stack: 0,
	stackTotal: 24};
	 this.metricsArray.fcn["sin"] = {file: "C:\\Program Files\\MATLAB\\R2018b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sqrt"] = {file: "C:\\Program Files\\MATLAB\\R2018b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
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
	 this.codeMetricsSummary = '<a href="FSW_0123_metrics.html">Global Memory: 352(bytes) Maximum Stack: 248(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
