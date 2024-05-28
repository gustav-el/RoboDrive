<script lang="ts">
	import '../app.postcss';
	import { AppShell, AppBar } from '@skeletonlabs/skeleton';


	function goToHome()
		{
			window.location.href = '/';
		}
	function goToDrivePage()
	{
		window.location.href = '/Driverpage'
	}
	function goToInfo()
	{
		window.location.href='/Infopage'
	}
	
</script>

<!-- App Shell -->
<AppShell>

	<svelte:fragment slot="header">
		<!-- App Bar -->
		<AppBar>
			<svelte:fragment slot="lead">
				<strong class="text-xl uppercase">DriverBot</strong>
			</svelte:fragment>
			<svelte:fragment slot="trail">
				<div class="container h-11 mx-auto flex justify-start items-start" >
					
					<button class="btn variant-filled-primary" on:click={goToHome}>Home </button>
					<button class="btn variant-filled-primary" on:click={goToDrivePage}>Drive</button>
					<button class="btn variant-filled-primary" on:click={goToInfo}>Info</button>
				</div>
			</svelte:fragment>
		</AppBar>
	</svelte:fragment>
	<!-- Page Route Content -->
	<slot />
</AppShell>
