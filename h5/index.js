$(document).ready(function(){
	var music_play_btn = $('.play-bg-music'),i=0;
	setInterval(function(){
		i++;
		music_play_btn[0].style.transform= 'rotate('+ i +'deg)';
	},16);
	music_play_btn.click(function(){
		if($('.bg-music')[0].paused){
			$(".bg-music")[0].play();
		}else{
			$('.bg-music')[0].pause();
		}
	})
});