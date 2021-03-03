const signalingUrl = "wss://ayame-labo.shiguredo.jp/signaling";

// パラメーターのパース
const params = window.location.search;
const searchParams = new URLSearchParams(params);
if (!searchParams.has("roomId") || !searchParams.has("signalingKey")) {
    alert("roomIdとsignalingKeyをクエリにセットしてください．");
}
const roomId = searchParams.get("roomId");
const signalingKey = searchParams.get("signalingKey");
console.log("roomId: ", roomId, ", signalingKey: ", signalingKey);

// Ayame
let dataChannel = null;
const conn = Ayame.connection(signalingUrl, roomId);
conn.options.video.direction = 'recvonly';
conn.options.audio.direction = 'recvonly';
conn.options.video.codec = "H264"; //デスクトップChrome系のブラウザでのみ反映される
conn.options.signalingKey = signalingKey;
const startConn = async () => {
    conn.on('open', async (e) => {
        dataChannel = await conn.createDataChannel('dataChannel');
        dataChannel.onmessage = (e) => {
            console.log('data received: ', e.data);
        };
    });
    await conn.connect(null);
    conn.on('disconnect', (e) => console.log(e));
    conn.on('addstream', (e) => {
        document.querySelector('#remote-video').srcObject = e.stream;
    });
};
function sendData(data) {
    dataChannel.send(data);
}

// ボタン
document.querySelector('#connect').onclick = startConn;
document.querySelector('#disconnect').onclick = () => {
    conn.disconnect();
};
document.querySelector('#send0').onclick = () => {
    sendData("0");
    console.log("send 0");
};
document.querySelector('#send1').onclick = () => {
    sendData("1");
    console.log("send 1");
}