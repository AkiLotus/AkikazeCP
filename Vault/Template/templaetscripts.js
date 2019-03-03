function fileName() { return document.fileName(); }
function fileUrl() { return document.url(); }
function encoding() { return document.encoding(); }
function selection() { return view.selectedText(); }
function year() { return new Date().getFullYear(); }
function upper(x) { return x.toUpperCase(); }
function lower(x) { return x.toLowerCase(); }
function date() {
	var d = new Date(),
		minutes = d.getMinutes().toString().length == 1 ? '0'+d.getMinutes() : d.getMinutes(),
		hours = d.getHours().toString().length == 1 ? '0'+d.getHours() : d.getHours(),
		ampm = d.getHours() >= 12 ? 'pm' : 'am',
		months = ['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec'],
		days = ['Sun','Mon','Tue','Wed','Thu','Fri','Sat'];
	var DDate = '';
	DDate = DDate + days[d.getDay()].toString();
	DDate = DDate + ' ';
	DDate = DDate + months[d.getMonth()].toString();
	DDate = DDate + ' ';
	DDate = DDate + d.getDate().toString();
	DDate = DDate + ' ';
	DDate = DDate + d.getFullYear().toString();
	DDate = DDate + ' ';
	DDate = DDate + hours.toString();
	DDate = DDate + ':';
	DDate = DDate + minutes.toString();
	DDate = DDate + ampm.toString();
	var n = DDate.length, i;
	for (i = n; i < 29; i++) {
		DDate = DDate + ' ';
	}
	DDate += '**'; return DDate;
}
function fileName_extended() {
	var name = document.fileName();
	var n = name.length, i;
	for (i = n; i < 32; i++) {
		name = name + ' ';
	}
	name += '**'; return name;
}
