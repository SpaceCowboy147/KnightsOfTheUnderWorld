

// .cpp files implement the .h files

#include "Goblin.h"

#include "Engine.h"

// Sets default values
AGoblin::AGoblin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false; // will allow camera to rotate but not character

	GetCharacterMovement()->bOrientRotationToMovement = true; // allows character look forward  where you're moving. hope that makes sense 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2; //slight control while in air

	CameraBoom = CreateAbstractDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom")); //name of spring arm in unreal
	CameraBoom->SetupAttachment(RootComponent); //root component is capsule inside unreal
	CameraBoom->TargetArmLength = 300.0f; //sets how far camera is from player
	CameraBoom->bUsePawnControlRotation = true; // rotate arm based on conttroller (spring arm)

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera")); 
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); //attaches camera to spring arm
	FollowCamera->bUsePawnControlRotation = false; //camera does not rotate relative to the arm

	// Creates the collection sphere. The sphere is used by the player to pickup AutoPickups . Every AutoPickup inside the sphere will be picked up automatically
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.f);

	bDead = false; //default value so you are not dead.


	
}


// Called when the game starts or when spawned
void AGoblin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoblin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AGoblin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput); //turn is name of input on UE4. binds controls to that inputs yaw movement
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput); //same as before just looking up and down with input LookUp

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump); //jumps when pressed
		PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping); //stops jumping when released

		PlayerInputComponent->BindAxis("Forward", this, &AGoblin::MoveForward);
		PlayerInputComponent->BindAxis("horizontal", this, &AGoblin::MoveRight);

		InputComponent->BindAction("Pickup", IE_Pressed, this, &AGoblin::BeginPickup);
		InputComponent->BindAction("Pickup", IE_Released, this, &AGoblin::EndPickup);

		InputComponent->BindAction("OpenInventory", IE_Pressed, this, &AGoblin::ShowInventory);
}



void AGoblin::BeginPickup()
{
	bIsPickingUp = true;

}
void AGoblin::EndPickup() {
	
	bIsPickingUp = false;
}
void AGoblin::ShowInventory() {

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("This is our inventory"));
}

void AGoblin::MoveForward(float Axis)
{

	if (!bDead) {
		const FRotator Rotation = Controller->GetControlRotation(); //moves character if not dead
		const FRotator YawRotation(0, Rotation.Yaw, 0); //finds forward direction
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); //calculates forward rotation
		AddMovementInput(Direction, Axis);
	}


}

void AGoblin::MoveRight(float Axis)
{
	if (!bDead) {
		const FRotator Rotation = Controller->GetControlRotation(); //moves character if not dead
		const FRotator YawRotation(0, Rotation.Yaw, 0); //finds forward direction
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); //calculates forward rotation
		AddMovementInput(Direction, Axis);
	}


}
