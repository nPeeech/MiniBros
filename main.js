function main() {
    // パラメーターのパース
    const params = window.location.search;
    const searchParams = new URLSearchParams(params);
    const roomId = searchParams.get("roomId");
    const signalingKey = searchParams.get("signalingKey");

    
}

window.onload = main;