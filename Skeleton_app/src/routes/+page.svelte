<div class="container h-full mx-auto flex justify-center items-center">
	<div class="space-y-10 text-center flex flex-col items-center">

	
		<h2 class="h2">Home</h2>
		
		<div class="flex items-center"> 
			<h2 class ="mr-2"> Exit</h2>
			<button type="button" class="btn-icon variant-filled">
				<span class="material-symbols-outlined">exit_to_app</span></button>
		</div>
	</div>
</div>


<style lang="postcss">

	@keyframes glow {
		0% {
			@apply bg-primary-400/50;
		}
		33% {
			@apply bg-secondary-400/50;
		}
		66% {
			@apply bg-tertiary-400/50;
		}
		100% {
			@apply bg-primary-400/50;
		}
	}
	@keyframes pulse {
		50% {
			transform: scale(1.5);
		}
	}
</style>
