let app = Vue.createApp({
    data: function(){
        return {
            biodata:{
                name: 'Ahmad Fadillah',
                born: 'Jakarta, 15 Oktober 2002',
                address: 'JL. Kayu Tinggi Cakung Timur Jakarta Timur DKI Jakarta',
                gender: 'Male',
                religion: 'Islam',
                phoneNumber: '+6289647107815'
            },
            home: {
                about: 'I am a entry-level professional website developer with okay knowlegde about client-side and server-side. Currently studied as a college student in Institute Technology Of Sumatera. Seeking a junior web developer position to expand my skills.',
                experience: 'I am currently dont have any experience...',
                education:{
                    sd: 'SD: SDN CAKUNG TIMUR 03',
                    smp: 'SMP: SMPN CAKUNG TIMUR 234',
                    sma: 'SMA: SMAN CAKUNG TIMUR 89',
                    univ: 'UNIVERSITAS: INSTITUT TEKNOLOGI SUMATERA'
                },
                social:{
                    facebook: 'Fadhil',
                    insta: '@ahmdfdhilah',
                    twitter: '@Hiorynee',
                    whatsapp: '089647107815',
                    github: '@Hiorynee'
                }
            }
        }
    }
}
    )
app.mount('#app')