// Body styling
Object.assign(document.body.style, {
    backgroundColor: "#f4f4f4",
    margin: "0px",
    padding: "0px"
});
// Card content
const content = [
    { svg: "svg/ruler.svg", color: "#ffe082", title: "Education" },
    { svg: "svg/credentialing.svg", color: "#c8e6c9", title: "Credentialing" },
    { svg: "svg/wallet.svg", color: "#e1bee7", title: "Wallet" },
    { svg: "svg/human.svg", color: "#e3f2fd", title: "Human Resources" }
];

// Style element
const style = document.createElement("style");
style.innerHTML = `
    #cardContainer {
        margin: 15% 20px 0 20px;
        display: flex;
        justify-content: center;
        align-items: center;
        gap: 20px; 
    }
    .card {
        width: 150px;
        height: 180px;
        background-color: #fff;
        border-radius: 8px;
        box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        text-align: center;
        cursor: pointer;
        transition: transform 0.3s ease, box-shadow 0.3s ease, background-color 0.3s ease;
    }
    .card:hover {
        transform: scale(1.05);
        box-shadow: 0 6px 15px rgba(0, 0, 0, 0.2);
    }
    .cardTitle {
        color: #333;
        font-size: 14px;
        margin-top: 10px;
    }
`;
document.head.appendChild(style);

// Reference to container
const cardContainer = document.getElementById("cardContainer");

// Create cards
content.forEach(item => {
    const card = document.createElement("div");
    card.className = "card";
    // card.style.backgroundColor = item.color;
    card.innerHTML = `
        <div class="cardIcon">
            <img src="${item.svg}" alt="icon" width="50" height="50">
        </div>
        <div class="cardTitle">${item.title}</div>
    `;
    cardContainer.appendChild(card);
    card.setAttribute("data-color", item.color);
    card.setAttribute("data-color", item.color);
    card.addEventListener("mouseover", () => {
    card.style.backgroundColor = item.color;
    });
    card.addEventListener("mouseout", () => {
        card.style.backgroundColor = "#fff";
    });

});
