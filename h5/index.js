$(document).ready(function(){
	var music_play_btn = $('.play-bg-music'),i=0;

	var sound = new Audio();
    sound.src = "./Star_Sky.mp3";
    sound.play();

	setInterval(function(){
		i++;
		music_play_btn[0].style.transform= 'rotate('+ i +'deg)';
	},16);

	music_play_btn.click(function(){
		if(sound.paused){
			sound.play();
		}else{
			sound.pause();
		}
	})
});